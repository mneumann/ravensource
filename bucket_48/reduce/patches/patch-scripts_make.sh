--- scripts/make.sh.orig	2023-08-17 22:59:10 UTC
+++ scripts/make.sh
@@ -127,11 +127,6 @@ then
   *cygwin* | *windows*)
     list="cslbuild/*-cygwin*/csl cslbuild/*-windows*/csl"
     ;;
-  mac_*)
-    host1=${host/aarch64/universal}
-    host1=${host1/x86_64/universal}
-    list="cslbuild/*${host}*/csl cslbuild/*${host1}*/csl"
-    ;;
   *)
     list="cslbuild/*${host}*/csl"
     ;;
