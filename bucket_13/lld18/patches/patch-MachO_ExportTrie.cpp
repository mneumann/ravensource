--- MachO/ExportTrie.cpp.orig	2024-06-15 17:21:32 UTC
+++ MachO/ExportTrie.cpp
@@ -34,6 +34,22 @@
 //
 //===----------------------------------------------------------------------===//
 
+#ifdef __sun__
+#include <string.h>
+
+extern "C" {
+  static size_t
+  strnlen(const char *s, size_t maxlen)
+  {
+       size_t len;
+       for (len = 0; len < maxlen; len++, s++) {
+               if (!*s) break;
+       }
+       return (len);
+  }
+}
+#endif
+
 #include "ExportTrie.h"
 #include "Symbols.h"
 
