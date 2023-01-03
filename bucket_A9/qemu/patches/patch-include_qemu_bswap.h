--- include/qemu/bswap.h.orig	2022-12-14 16:28:45 UTC
+++ include/qemu/bswap.h
@@ -4,7 +4,7 @@
 #ifdef CONFIG_MACHINE_BSWAP_H
 # include <sys/endian.h>
 # include <machine/bswap.h>
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 # include <sys/endian.h>
 #elif defined(__HAIKU__)
 # include <endian.h>
