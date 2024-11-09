NetBSD does not support uselocale

--- Source/ThirdParty/skia/src/gpu/ganesh/GrAutoLocaleSetter.h.orig	2024-08-19 06:28:38 UTC
+++ Source/ThirdParty/skia/src/gpu/ganesh/GrAutoLocaleSetter.h
@@ -27,7 +27,7 @@
 #define HAVE_XLOCALE 0
 #endif
 
-#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION)
+#if defined(SK_BUILD_FOR_ANDROID) || defined(__UCLIBC__) || defined(_NEWLIB_VERSION) || defined(__NetBSD__)
 #define HAVE_LOCALE_T 0
 #else
 #define HAVE_LOCALE_T 1