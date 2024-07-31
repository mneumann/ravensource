--- vendor/openssl-sys-0.9.92/build/main.rs.orig	2006-07-24 01:21:28 UTC
+++ vendor/openssl-sys-0.9.92/build/main.rs
@@ -273,6 +273,8 @@ See rust-openssl documentation for more
             (3, 7, 1) => ('3', '7', '1'),
             (3, 7, _) => ('3', '7', 'x'),
             (3, 8, 0) => ('3', '8', '0'),
+            (3, 8, 1) => ('3', '8', '1'),
+            (3, 8, _) => ('3', '8', 'x'),
             _ => version_error(),
         };
 
@@ -315,7 +317,7 @@ fn version_error() -> ! {
         "
 
 This crate is only compatible with OpenSSL (version 1.0.1 through 1.1.1, or 3.0.0), or LibreSSL 2.5
-through 3.8.0, but a different version of OpenSSL was found. The build is now aborting
+through 3.8.x, but a different version of OpenSSL was found. The build is now aborting
 due to this version mismatch.
 
 "
