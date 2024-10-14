--- hw/ppc/mac_oldworld.c.orig	2024-09-04 17:40:41 UTC
+++ hw/ppc/mac_oldworld.c
@@ -66,6 +66,11 @@
 
 #define GRACKLE_BASE 0xfec00000
 
+/* FreeBSD headers define this */
+#ifdef round_page
+#undef round_page
+#endif
+
 static void fw_cfg_boot_set(void *opaque, const char *boot_device,
                             Error **errp)
 {
