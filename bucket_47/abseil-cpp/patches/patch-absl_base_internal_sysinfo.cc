--- absl/base/internal/sysinfo.cc.orig	2023-08-07 18:40:00 UTC
+++ absl/base/internal/sysinfo.cc
@@ -26,11 +26,15 @@
 #include <unistd.h>
 #endif
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__DragonFly__)
 #include <sys/syscall.h>
 #endif
 
-#if defined(__APPLE__) || defined(__FreeBSD__)
+#if defined(__NetBSD__)
+#include <lwp.h> // For _lwp_self()
+#endif
+
+#if defined(__APPLE__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/sysctl.h>
 #endif
 
@@ -432,6 +436,18 @@ pid_t GetTID() {
   return static_cast<pid_t>(tid);
 }
 
+#elif defined(__DragonFly__)
+
+pid_t GetTID() {
+  return syscall(SYS_lwp_gettid);
+}
+
+#elif defined(__NetBSD__)
+
+pid_t GetTID() {
+  return static_cast<pid_t>(_lwp_self());
+}
+
 #elif defined(__native_client__)
 
 pid_t GetTID() {
