--- external/skia/UnpackedTarball_skia.mk.orig	2023-05-31 16:13:22 UTC
+++ external/skia/UnpackedTarball_skia.mk
@@ -41,6 +41,8 @@ skia_patches := \
     constexpr-template.patch.0 \
     missing-include.patch.0 \
     tdf147342.patch.0 \
+    gfx-skia-skia-src-core-SkCpu.cpp.patch.0 \
+    netbsd.patch.0 \
 
 $(eval $(call gb_UnpackedTarball_set_patchlevel,skia,1))
 
