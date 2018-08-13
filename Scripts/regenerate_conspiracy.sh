#!/bin/sh

maintainer=marino
repo=/usr/raven #/home/marino/github/Ravenports
myid=$(id -un)
today=$(date "+%d %h %Y %H:%M")
message="Ravenports generated: ${today}"

if [ "${myid}" != "root" ]; then
   echo "Only root is allowed to regenerate ports (which requires using root-only ravenadm)"
   exit 1
fi

# Requires ravenadm v1.06 or later
CONSPIR=$(/raven/bin/ravenadm dev info D)

RPATH=$(realpath $0)
SCRIPTSDIR=$(dirname ${RPATH})
RAVENSRC=$(dirname ${SCRIPTSDIR})
HEXRANGE="0 1 2 3 4 5 6 7 8 9 A B C D E F"
PD_AWK=${SCRIPTSDIR}/miscellaneous/port_dates.awk
PD_FILE=${repo}/Mk/Misc/port_dates
CONVARS=${repo}/Mk/Misc/conspiracy_variants
TMPFULL=/tmp/port_dates
WARNING="Autogenerated -- Do not edit!"
PATTERN=RESERVED_WARNING
DATADIR=${SCRIPTSDIR}/Ravenports_Mk

for F in GID UID; do
   sed "s|${PATTERN}|${WARNING}|" ${DATADIR}/${F}.ravenports > ${CONSPIR}/Mk/Templates/${F}.ravenports
done
for F in information versions; do
   sed "s|${PATTERN}|${WARNING}|" ${DATADIR}/raven.${F}.mk > ${CONSPIR}/Mk/raven.${F}.mk
done
cp ${DATADIR}/raverreq ${CONSPIR}/Mk/Misc/

for D1 in ${HEXRANGE}; do
  for D0 in ${HEXRANGE}; do
    BK=${RAVENSRC}/bucket_${D1}${D0}
    if [ -d ${BK} ]; then
      queue=$(find ${BK} -depth -maxdepth 1 -mindepth 1 -type d)
      for port in ${queue}; do
         echo "=============  ${port}"
         /raven/bin/ravenadm dev buildsheet ${port} save
      done
    fi
  done
done

/raven/bin/ravenadm dev generate-index

if [ $# -lt 1 -o "${1}" != "confirm" ]; then
   echo "add 'confirm' argument to regenerate (again) but with a commit this time"
   exit 0;
fi

(cd ${repo} && git add "." && git commit -m "${message}")
(cd ${repo} && git log --format="format:%ct" --name-only) | \
  awk -f ${PD_AWK} | sort > ${TMPFULL}
rm -f ${PD_FILE}
while read namebase timeS timeF
do
   grep -q " ${namebase} " ${CONVARS}
   if [ $? -eq 0 ]; then
      echo "${namebase} ${timeS} ${timeF}" >> ${PD_FILE}
   fi
done < ${TMPFULL}
rm -f ${TMPFULL}
(cd ${repo}/Mk && git add Misc)

chown -R ${maintainer} ${repo}
