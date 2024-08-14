--- libvips/iofuncs/memory.c.orig	2024-08-11 14:53:44 UTC
+++ libvips/iofuncs/memory.c
@@ -70,7 +70,7 @@
 #include <stdarg.h>
 #include <string.h>
 #if defined(HAVE__ALIGNED_MALLOC) || defined(HAVE_MEMALIGN)
-#include <malloc.h>
+#include <sys/malloc.h>
 #endif
 
 #include <vips/vips.h>
