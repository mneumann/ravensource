$NetBSD: patch-sope-core_NGStreams_NGDescriptorFunctions.m,v 1.1 2021/06/14 16:51:39 gdt Exp $

ttyname_r comes from <unistd.h> which is already included

--- sope-core/NGStreams/NGDescriptorFunctions.m.orig	2024-10-08 10:26:48 UTC
+++ sope-core/NGStreams/NGDescriptorFunctions.m
@@ -387,9 +387,6 @@ NSString *NGDescriptorGetTtyName(int _fd
 #endif
   {
 #if HAVE_TTYNAME_R
-#  ifndef sparc
-   extern int ttyname_r(int, char*, size_t);
-#  endif
 #  ifdef _POSIX_PATH_MAX
     char namebuffer[_POSIX_PATH_MAX + 128];
 #  else
