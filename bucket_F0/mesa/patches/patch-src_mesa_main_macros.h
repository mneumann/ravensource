--- src/mesa/main/macros.h.orig	2019-12-18 18:36:01 UTC
+++ src/mesa/main/macros.h
@@ -36,6 +36,7 @@
 #include "util/rounding.h"
 #include "imports.h"
 
+#undef ALIGN
 
 /**
  * \name Integer / float conversion for colors, normals, etc.
