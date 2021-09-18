--- vendor/openssl-sys/build/main.rs.orig	2021-07-26 15:20:39 UTC
+++ vendor/openssl-sys/build/main.rs
@@ -232,6 +232,7 @@ See rust-openssl README for more informa
             (3, 2, _) => ('3', '2', 'x'),
             (3, 3, 0) => ('3', '3', '0'),
             (3, 3, 1) => ('3', '3', '1'),
+            (3, 3, _) => ('3', '3', 'x'),
             _ => version_error(),
         };
 
@@ -272,7 +273,7 @@ fn version_error() -> ! {
         "
 
 This crate is only compatible with OpenSSL 1.0.1 through 1.1.1, or LibreSSL 2.5
-through 3.3.1, but a different version of OpenSSL was found. The build is now aborting
+through 3.3.x, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
