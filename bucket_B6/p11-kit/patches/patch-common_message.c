--- common/message.c.orig	2023-06-28 09:43:53 UTC
+++ common/message.c
@@ -41,7 +41,9 @@
  * Oh god. glibc is nasty. Changes behavior and definitions of POSIX
  * functions to completely different signatures depending on defines
  */
+#ifdef __linux__
 #define _POSIX_C_SOURCE 200112L
+#endif
 
 #include "compat.h"
 #define P11_DEBUG_FLAG P11_DEBUG_LIB
