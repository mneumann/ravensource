--- roms/u-boot/lib/bch.c.orig	2024-07-16 21:36:04 UTC
+++ roms/u-boot/lib/bch.c
@@ -63,7 +63,7 @@
 #include <linux/bitops.h>
 #else
 #include <errno.h>
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #elif defined(__APPLE__)
 #include <machine/endian.h>
