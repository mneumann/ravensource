--- coreconf/arch.mk.orig	2024-05-07 16:00:24 UTC
+++ coreconf/arch.mk
@@ -97,6 +97,14 @@ ifeq ($(OS_ARCH),Linux)
     include $(CORE_DEPTH)/coreconf/Linux.mk
 endif
 
+ifeq ($(OS_ARCH),DragonFly)
+OS_RELEASE := @OS_RELEASE@
+endif
+
+ifeq ($(OS_ARCH),MidnightBSD)
+OS_RELEASE := @OS_RELEASE@
+endif
+
 # Since all uses of OS_ARCH that follow affect only userland, we can
 # merge other Glibc systems with Linux here.
 ifeq ($(OS_ARCH),GNU)
