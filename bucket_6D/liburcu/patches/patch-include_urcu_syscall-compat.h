--- include/urcu/syscall-compat.h.orig	2024-11-20 15:54:04 UTC
+++ include/urcu/syscall-compat.h
@@ -16,6 +16,7 @@
 
 #elif defined(__CYGWIN__) || defined(__APPLE__) || \
 	defined(__FreeBSD__) || defined(__DragonFly__) || \
+	defined(__NetBSD__) || \
 	defined(__OpenBSD__)
 /* Don't include anything on these platforms. */
 
