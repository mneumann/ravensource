--- lib/librdkafka-2.3.0/src/rdendian.h.orig	2024-04-27 14:05:20 UTC
+++ lib/librdkafka-2.3.0/src/rdendian.h
@@ -40,7 +40,7 @@
  *   le64toh()
  */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #elif defined __GLIBC__
 #include <endian.h>
