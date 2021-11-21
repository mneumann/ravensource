--- Utilities/cmlibuv/src/unix/core.c.orig	2021-11-18 15:51:22 UTC
+++ Utilities/cmlibuv/src/unix/core.c
@@ -85,6 +85,11 @@ extern char** environ;
 # include <sys/cpuset.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__NetBSD__)
+# include <sys/param.h>
+# include <sys/sched.h>
+#endif
+
 #if defined(__MVS__)
 #include <sys/ioctl.h>
 #endif
