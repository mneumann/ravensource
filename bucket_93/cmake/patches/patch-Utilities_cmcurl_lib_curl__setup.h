--- Utilities/cmcurl/lib/curl_setup.h.orig	2024-11-06 13:41:37 UTC
+++ Utilities/cmcurl/lib/curl_setup.h
@@ -24,6 +24,7 @@
  *
  ***************************************************************************/
 
+#define __BSD_VISIBLE 1
 #if defined(BUILDING_LIBCURL) && !defined(CURL_NO_OLDIES)
 #define CURL_NO_OLDIES
 #endif
