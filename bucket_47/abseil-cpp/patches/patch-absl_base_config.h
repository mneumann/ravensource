--- absl/base/config.h.orig	2024-01-22 17:59:25 UTC
+++ absl/base/config.h
@@ -414,6 +414,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_MMAP
 #error ABSL_HAVE_MMAP cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) ||    \
+    defined(__DragonFly__) ||                                                \
     defined(_AIX) || defined(__ros__) || defined(__native_client__) ||       \
     defined(__asmjs__) || defined(__EMSCRIPTEN__) || defined(__Fuchsia__) || \
     defined(__sun) || defined(__ASYLO__) || defined(__myriad2__) ||          \
@@ -429,6 +430,7 @@ static_assert(ABSL_INTERNAL_INLINE_NAMES
 #ifdef ABSL_HAVE_PTHREAD_GETSCHEDPARAM
 #error ABSL_HAVE_PTHREAD_GETSCHEDPARAM cannot be directly set
 #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || \
+    defined(__DragonFly__) ||                                             \
     defined(_AIX) || defined(__ros__) || defined(__OpenBSD__) ||          \
     defined(__NetBSD__) || defined(__VXWORKS__)
 #define ABSL_HAVE_PTHREAD_GETSCHEDPARAM 1
