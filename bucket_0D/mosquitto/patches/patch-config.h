--- config.h.orig	2024-10-16 19:25:30 UTC
+++ config.h
@@ -6,7 +6,7 @@
 
 #ifdef __APPLE__
 #  define __DARWIN_C_SOURCE
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__SYMBIAN32__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__SYMBIAN32__) || defined(__DragonFly__)
 #  define HAVE_NETINET_IN_H
 #elif defined(__QNX__)
 #  define _XOPEN_SOURCE 600
