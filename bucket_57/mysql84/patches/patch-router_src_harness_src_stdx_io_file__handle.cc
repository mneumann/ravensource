--- router/src/harness/src/stdx/io/file_handle.cc.orig	2024-06-03 11:39:00 UTC
+++ router/src/harness/src/stdx/io/file_handle.cc
@@ -284,7 +284,10 @@ file_handle::current_path() const noexce
 
   return {path_name};
 #else
-#error unsupported OS
+  // don't use this
+  std::string path_name;
+  path_name.resize(1025);
+  return {path_name};
 #endif
 }
 
