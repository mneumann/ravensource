--- libmysql/dns_srv.cc.orig	2021-03-22 08:44:50 UTC
+++ libmysql/dns_srv.cc
@@ -31,7 +31,7 @@
 
 #ifdef HAVE_UNIX_DNS_SRV
 
-#ifdef __FreeBSD__
+#if defined __FreeBSD__ | defined __DragonFly__
 #include <netinet/in.h>
 #endif
 #include <netdb.h>
