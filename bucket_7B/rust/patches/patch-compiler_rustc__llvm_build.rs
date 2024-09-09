--- compiler/rustc_llvm/build.rs.orig	2024-09-04 15:07:06 UTC
+++ compiler/rustc_llvm/build.rs
@@ -329,24 +329,7 @@ fn main() {
     }
 
     let llvm_static_stdcpp = tracked_env_var_os("LLVM_STATIC_STDCPP");
-    let llvm_use_libcxx = tracked_env_var_os("LLVM_USE_LIBCXX");
-
-    let stdcppname = if target.contains("openbsd") {
-        if target.contains("sparc64") { "estdc++" } else { "c++" }
-    } else if target.contains("darwin")
-        || target.contains("freebsd")
-        || target.contains("windows-gnullvm")
-        || target.contains("aix")
-    {
-        "c++"
-    } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
-        // NetBSD uses a separate library when relocation is required
-        "stdc++_p"
-    } else if llvm_use_libcxx.is_some() {
-        "c++"
-    } else {
-        "stdc++"
-    };
+    let stdcppname = "stdc++";
 
     // RISC-V GCC erroneously requires libatomic for sub-word
     // atomic operations. Some BSD uses Clang as its system
