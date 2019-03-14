--- Source/WebKit/Platform/unix/SharedMemoryUnix.cpp.orig	2019-02-12 11:21:18 UTC
+++ Source/WebKit/Platform/unix/SharedMemoryUnix.cpp
@@ -134,7 +134,13 @@ static int createSharedMemory()
 
     CString tempName;
     for (int tries = 0; fileDescriptor == -1 && tries < 10; ++tries) {
-        String name = String("/WK2SharedMemory.") + String::number(static_cast<unsigned>(WTF::randomNumber() * (std::numeric_limits<unsigned>::max() + 1.0)));
+        String name =
+#ifdef __DragonFly__
+                      String("/tmp/WK2SharedMemory.")
+#else
+                      String("/WK2SharedMemory.")
+#endif
+                      + String::number(static_cast<unsigned>(WTF::randomNumber() * (std::numeric_limits<unsigned>::max() + 1.0)));
         tempName = name.utf8();
 
         do {
