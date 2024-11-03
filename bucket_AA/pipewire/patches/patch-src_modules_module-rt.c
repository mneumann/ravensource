--- src/modules/module-rt.c.orig	2024-10-23 07:44:10 UTC
+++ src/modules/module-rt.c
@@ -35,6 +35,9 @@
 #if defined(__FreeBSD__) || defined(__MidnightBSD__)
 #include <sys/thr.h>
 #endif
+#if defined(__NetBSD__)
+#include <lwp.h>
+#endif
 #if defined(__GNU__)
 #include <hurd.h>
 #endif
@@ -239,6 +242,10 @@ static pid_t _gettid(void)
 	return (pid_t) gettid();
 #elif defined(__linux__)
 	return syscall(SYS_gettid);
+#elif defined(__DragonFly__)
+	return syscall(SYS_lwp_gettid);
+#elif defined(__NetBSD__)
+	return (pid_t)_lwp_self();
 #elif defined(__FreeBSD__) || defined(__MidnightBSD__)
 	long pid;
 	thr_self(&pid);
