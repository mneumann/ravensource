--- desktop/unx/source/pagein.c.orig	2020-07-29 19:29:17 UTC
+++ desktop/unx/source/pagein.c
@@ -25,7 +25,9 @@
 #include <stdio.h>
 #include <string.h>
 #include <sys/stat.h>
+#ifdef LINUX
 #include <sys/sysmacros.h>
+#endif
 #include <sys/types.h>
 
 /* do_pagein */
