# define ETIME as ETIMEOUT same as in intel driver
#
--- src/gallium/drivers/vc4/vc4_bufmgr.c.orig	2019-11-06 16:53:31 UTC
+++ src/gallium/drivers/vc4/vc4_bufmgr.c
@@ -27,6 +27,9 @@
 #include <fcntl.h>
 #include <xf86drm.h>
 #include <xf86drmMode.h>
+#ifndef ETIME
+#define ETIME ETIMEDOUT
+#endif
 
 #include "util/u_hash_table.h"
 #include "util/u_memory.h"
