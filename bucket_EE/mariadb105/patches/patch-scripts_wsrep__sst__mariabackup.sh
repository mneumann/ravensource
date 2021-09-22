--- scripts/wsrep_sst_mariabackup.sh.orig	2021-08-03 08:29:08 UTC
+++ scripts/wsrep_sst_mariabackup.sh
@@ -696,7 +696,7 @@ recv_joiner()
     local ltcmd="$tcmd"
     if [ $tmt -gt 0 ]; then
         if [ -n "$(command -v timeout)" ]; then
-            if timeout --help | grep -qw -- '-k'; then
+            if timeout --help 2>&1 | grep -qw -- '-k'; then
                 ltcmd="timeout -k $(( tmt+10 )) $tmt $tcmd"
             else
                 ltcmd="timeout -s9 $tmt $tcmd"
