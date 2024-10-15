--- cmake/ssl.cmake.orig	2024-09-24 11:37:21 UTC
+++ cmake/ssl.cmake
@@ -588,7 +588,7 @@ ENDFUNCTION(MYSQL_CHECK_SSL)
 # or INSTALL_LIBDIR      (Mac)
 # or INSTALL_PRIV_LIBDIR (Linux)
 MACRO(MYSQL_CHECK_SSL_DLLS)
-  IF (WITH_SSL_PATH AND (APPLE OR WIN32 OR LINUX_STANDALONE OR LINUX_RPM))
+  IF (WITH_SSL_PATH AND (APPLE OR WIN32))
     MESSAGE(STATUS "WITH_SSL_PATH ${WITH_SSL_PATH}")
     IF(LINUX)
       GET_FILENAME_COMPONENT(CRYPTO_EXT "${CRYPTO_LIBRARY}" EXT)
