--- cmake/Findzstd.cmake.orig	2022-02-27 20:03:02 UTC
+++ cmake/Findzstd.cmake
@@ -41,7 +41,7 @@ if(ZSTD_FROM_INTERNET)
 
   set(zstd_FOUND TRUE)
 else()
-  find_library(ZSTD_LIBRARY zstd)
+  find_library(ZSTD_LIBRARY zstd_pic)
   find_path(ZSTD_INCLUDE_DIR zstd.h)
 
   include(FindPackageHandleStandardArgs)
