--- gio/glocalfileinfo.c.orig	2022-12-21 21:16:58 UTC
+++ gio/glocalfileinfo.c
@@ -24,6 +24,10 @@
 
 #include "config.h"
 
+#ifdef __sun__
+#  define	_POSIX_PTHREAD_SEMANTICS 1
+#endif
+
 #include <glib.h>
 
 #ifdef HAVE_SYS_TIME_H
