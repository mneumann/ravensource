--- library/unwind/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ library/unwind/src/lib.rs
@@ -154,7 +154,7 @@ extern "C" {}
 extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 extern "C" {}
 
 #[cfg(target_os = "haiku")]
