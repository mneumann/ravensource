--- src/llvm-project/llvm/cmake/modules/AddLLVM.cmake.orig	2023-04-16 21:40:30 UTC
+++ src/llvm-project/llvm/cmake/modules/AddLLVM.cmake
@@ -2281,7 +2281,7 @@ function(llvm_setup_rpath name)
     set(_install_rpath "${LLVM_LIBRARY_OUTPUT_INTDIR}" "${CMAKE_INSTALL_PREFIX}/lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
   elseif(UNIX)
     set(_install_rpath "\$ORIGIN/../lib${LLVM_LIBDIR_SUFFIX}" ${extra_libdir})
-    if(${CMAKE_SYSTEM_NAME} MATCHES "(FreeBSD|DragonFly)")
+    if(${CMAKE_SYSTEM_NAME} MATCHES "(FreeBSD|DragonFly|MidnightBSD)")
       set_property(TARGET ${name} APPEND_STRING PROPERTY
                    LINK_FLAGS " -Wl,-z,origin ")
     endif()
