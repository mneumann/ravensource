--- src/util/os_file.c.orig	2024-10-03 15:38:59 UTC
+++ src/util/os_file.c
@@ -28,6 +28,9 @@
 #endif
 #endif
 
+#ifndef ENODATA
+#define ENODATA ENOATTR
+#endif
 
 FILE *
 os_file_create_unique(const char *filename, int filemode)
