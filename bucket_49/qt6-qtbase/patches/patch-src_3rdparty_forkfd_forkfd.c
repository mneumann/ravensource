--- src/3rdparty/forkfd/forkfd.c.orig	2024-03-19 15:46:43 UTC
+++ src/3rdparty/forkfd/forkfd.c
@@ -78,9 +78,11 @@
 #endif
 #if (defined(__FreeBSD__) && defined(__FreeBSD_version) && __FreeBSD_version >= 1000032) || \
     (defined(__OpenBSD__) && OpenBSD >= 201505) || \
+    defined(__MidnightBSD__) || \
     (defined(__NetBSD__) && __NetBSD_Version__ >= 600000000)
 #  define HAVE_PIPE2    1
 #endif
+
 #if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__FreeBSD_kernel__) || \
     defined(__OpenBSD__) || defined(__NetBSD__) || defined(__APPLE__)
 #  define HAVE_WAIT4    1
