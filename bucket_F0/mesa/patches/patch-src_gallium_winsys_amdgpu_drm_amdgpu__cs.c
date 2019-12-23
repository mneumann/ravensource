--- src/gallium/winsys/amdgpu/drm/amdgpu_cs.c.orig	2019-12-18 18:36:00 UTC
+++ src/gallium/winsys/amdgpu/drm/amdgpu_cs.c
@@ -33,6 +33,10 @@
 
 #include "amd/common/sid.h"
 
+#ifdef __sun__
+#include <alloca.h>
+#endif
+
 DEBUG_GET_ONCE_BOOL_OPTION(noop, "RADEON_NOOP", false)
 
 #ifndef AMDGPU_IB_FLAG_RESET_GDS_MAX_WAVE_ID
