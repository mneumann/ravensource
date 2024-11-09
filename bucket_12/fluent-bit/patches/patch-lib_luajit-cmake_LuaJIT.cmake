--- lib/luajit-cmake/LuaJIT.cmake.orig	2024-11-04 22:36:47 UTC
+++ lib/luajit-cmake/LuaJIT.cmake
@@ -351,6 +351,8 @@ elseif(${CMAKE_SYSTEM_NAME} STREQUAL Hai
   set(TARGET_OS_FLAGS ${TARGET_OS_FLAGS} -DLUAJIT_OS=LUAJIT_OS_POSIX -DTARGET_OS_IPHONE=0)
 elseif(${CMAKE_SYSTEM_NAME} MATCHES "(Open|Free|Net)BSD")
   set(TARGET_OS_FLAGS ${TARGET_OS_FLAGS} -DLUAJIT_OS=LUAJIT_OS_BSD -DTARGET_OS_IPHONE=0)
+elseif(${CMAKE_SYSTEM_NAME} MATCHES "DragonFly|MidnightBSD")
+  set(TARGET_OS_FLAGS ${TARGET_OS_FLAGS} -DLUAJIT_OS=LUAJIT_OS_BSD -DTARGET_OS_IPHONE=0)
 elseif(${CMAKE_SYSTEM_NAME} STREQUAL iOS)
   set(TARGET_OS_FLAGS ${TARGET_OS_FLAGS} -DLUAJIT_OS=LUAJIT_OS_OSX -DTARGET_OS_IPHONE=1)
 else()
