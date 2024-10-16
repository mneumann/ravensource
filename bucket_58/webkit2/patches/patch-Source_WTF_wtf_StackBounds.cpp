$NetBSD: patch-Source_WTF_wtf_StackBounds.cpp,v 1.2 2018/10/24 18:31:07 leot Exp $

SunOS does not have pthread_getattr_np.

--- Source/WTF/wtf/StackBounds.cpp.orig	2024-08-19 06:28:38 UTC
+++ Source/WTF/wtf/StackBounds.cpp
@@ -112,6 +112,7 @@ StackBounds StackBounds::newThreadStackB
 #if HAVE(PTHREAD_NP_H) || OS(NETBSD)
     // e.g. on FreeBSD 5.4, neundorf@kde.org
     pthread_attr_get_np(thread, &sattr);
+#elif defined(__sun__)
 #else
     // FIXME: this function is non-portable; other POSIX systems may have different np alternatives
     pthread_getattr_np(thread, &sattr);
