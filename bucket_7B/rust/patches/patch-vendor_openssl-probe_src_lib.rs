--- vendor/openssl-probe/src/lib.rs.orig	2024-04-29 15:45:22 UTC
+++ vendor/openssl-probe/src/lib.rs
@@ -26,10 +26,7 @@ fn cert_dirs_iter() -> impl Iterator<Ite
     [
         "/var/ssl",
         "/usr/share/ssl",
-        "/usr/local/ssl",
-        "/usr/local/openssl",
-        "/usr/local/etc/openssl",
-        "/usr/local/share",
+        "@PREFIX@/share",
         "/usr/lib/ssl",
         "/usr/ssl",
         "/etc/openssl",
