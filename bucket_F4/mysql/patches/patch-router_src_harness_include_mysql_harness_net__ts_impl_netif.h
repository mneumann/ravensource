--- router/src/harness/include/mysql/harness/net_ts/impl/netif.h.orig	2024-09-24 11:37:21 UTC
+++ router/src/harness/include/mysql/harness/net_ts/impl/netif.h
@@ -34,6 +34,8 @@
 #include <string_view>
 
 #if defined(__linux__) || defined(__FreeBSD__) || defined(__APPLE__) || \
+    defined(__DragonFly__) || \
+    defined(__NetBSD__) || \
     defined(__sun__)
 #define HAVE_IFADDRS_H
 #endif
