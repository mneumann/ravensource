--- lib/byteorder.h.orig	2023-02-27 02:28:04 UTC
+++ lib/byteorder.h
@@ -49,7 +49,7 @@
 
 #if defined(__linux__) || defined(__OpenBSD__)
 #  include <endian.h>
-#elif defined(__FreeBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  include <sys/endian.h>
 #endif
 
