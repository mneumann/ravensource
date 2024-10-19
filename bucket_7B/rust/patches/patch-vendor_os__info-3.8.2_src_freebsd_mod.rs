--- vendor/os_info-3.8.2/src/freebsd/mod.rs.orig	2024-10-15 17:22:50 UTC
+++ vendor/os_info-3.8.2/src/freebsd/mod.rs
@@ -26,23 +26,7 @@ pub fn current_platform() -> Info {
 fn get_os() -> Type {
     match uname("-s").as_deref() {
         Some("MidnightBSD") => Type::MidnightBSD,
-        Some("FreeBSD") => {
-            let check_hardening = match Command::new("/sbin/sysctl")
-                .arg("hardening.version")
-                .output()
-            {
-                Ok(o) => o,
-                Err(e) => {
-                    error!("Failed to invoke '/sbin/sysctl': {:?}", e);
-                    return Type::FreeBSD;
-                }
-            };
-            match str::from_utf8(&check_hardening.stderr) {
-                Ok("0\n") => Type::HardenedBSD,
-                Ok(_) => Type::FreeBSD,
-                Err(_) => Type::FreeBSD,
-            }
-        }
+        Some("FreeBSD") => Type::FreeBSD,
         _ => Type::Unknown,
     }
 }
