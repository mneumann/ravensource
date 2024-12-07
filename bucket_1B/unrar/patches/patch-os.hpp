--- os.hpp.orig	2024-12-04 10:00:42 UTC
+++ os.hpp
@@ -170,6 +170,10 @@
 #endif
 #endif
 
+#ifdef OPENSSL_AES
+#include <openssl/evp.h>
+#endif // OPENSSL_AES
+
 #ifdef  S_IFLNK
 #define SAVE_LINKS
 #endif
