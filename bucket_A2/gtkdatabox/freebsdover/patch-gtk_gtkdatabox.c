--- gtk/gtkdatabox.c.orig	2021-04-20 00:39:22.000000000 +0200
+++ gtk/gtkdatabox.c	2022-12-31 23:24:06.804859000 +0100
@@ -84,6 +84,8 @@
 /* signals will be configured during class_init */
 static gint gtk_databox_signals[LAST_SIGNAL] = { 0 };
 
+#include <sys/param.h>
+#include <stdint.h>
 
 /* IDs of properties */
 enum {
