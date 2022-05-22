--- Source/cmake/OptionsCommon.cmake.orig	2022-02-23 11:41:53 UTC
+++ Source/cmake/OptionsCommon.cmake
@@ -128,10 +128,10 @@ endif ()
 option(USE_THIN_ARCHIVES "Produce all static libraries as thin archives" ${USE_THIN_ARCHIVES_DEFAULT})
 
 if (USE_THIN_ARCHIVES)
-    set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> crT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> crT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> rT <TARGET> <LINK_FLAGS> <OBJECTS>")
-    set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> rT <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> cr <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_C_ARCHIVE_CREATE "<CMAKE_AR> cr <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_CXX_ARCHIVE_APPEND "<CMAKE_AR> r <TARGET> <LINK_FLAGS> <OBJECTS>")
+    set(CMAKE_C_ARCHIVE_APPEND "<CMAKE_AR> r <TARGET> <LINK_FLAGS> <OBJECTS>")
 endif ()
 
 set(ENABLE_DEBUG_FISSION_DEFAULT OFF)
