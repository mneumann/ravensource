--- erts/etc/unix/run_erl.c.orig	2024-09-13 08:45:35 UTC
+++ erts/etc/unix/run_erl.c
@@ -81,7 +81,7 @@
 #ifdef HAVE_LIBUTIL_H
 #  include <libutil.h>
 #endif
-#ifdef HAVE_UTIL_H
+#ifdef __NetBSD__
 #  include <util.h>
 #endif
 #ifdef HAVE_SYS_IOCTL_H
