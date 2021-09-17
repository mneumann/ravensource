--- src/third_party/httplib.h.orig	2021-09-11 07:22:10 UTC
+++ src/third_party/httplib.h
@@ -161,7 +161,9 @@ using socket_t = SOCKET;
 
 #include <arpa/inet.h>
 #include <cstring>
+#ifndef __sun
 #include <ifaddrs.h>
+#endif
 #include <netdb.h>
 #include <netinet/in.h>
 #ifdef __linux__
