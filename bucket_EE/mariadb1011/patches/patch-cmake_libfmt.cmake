--- cmake/libfmt.cmake.orig	2024-10-29 14:32:31 UTC
+++ cmake/libfmt.cmake
@@ -15,7 +15,7 @@ MACRO(BUNDLE_LIBFMT)
   ExternalProject_Add(
     libfmt
     PREFIX   "${dir}"
-    URL      "https://github.com/fmtlib/fmt/releases/download/11.0.2/fmt-11.0.2.zip"
+    URL      "file:///distfiles/fmt-11.0.2.zip"
     URL_MD5 c622dca45ec3fc95254c48370a9f7a1d
     INSTALL_COMMAND ""
     CONFIGURE_COMMAND ""
