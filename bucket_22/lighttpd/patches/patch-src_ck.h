--- src/ck.h.orig	2024-02-19 17:09:46 UTC
+++ src/ck.h
@@ -23,6 +23,7 @@
 #define _RSIZE_T_DEFINED
 typedef size_t rsize_t;
 #endif
+#include <stdlib.h>
 #include <errno.h>
 #if defined(__DragonFly__)
 typedef int errno_t;
