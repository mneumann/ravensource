--- readline_cli.c.orig	2023-11-21 14:40:35 UTC
+++ readline_cli.c
@@ -19,6 +19,10 @@
 #include "config.h"
 #endif
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "php.h"
 
 #ifndef HAVE_RL_COMPLETION_MATCHES
