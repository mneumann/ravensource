--- src/amd/llvm/ac_llvm_build.h.orig	2022-02-09 20:10:39 UTC
+++ src/amd/llvm/ac_llvm_build.h
@@ -35,6 +35,10 @@
 
 #include <stdbool.h>
 
+#ifdef __sun
+#include <alloca.h>
+#endif
+
 #ifdef __cplusplus
 extern "C" {
 #endif
