--- lib/librdkafka-2.4.0/src/rdendian.h.orig	2024-12-19 17:21:21 UTC
+++ lib/librdkafka-2.4.0/src/rdendian.h
@@ -40,7 +40,7 @@
  *   le64toh()
  */
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #elif defined __GLIBC__
 #include <endian.h>
