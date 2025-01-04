$NetBSD: patch-glib_gthread.c,v 1.1 2024/04/09 16:57:18 wiz Exp $

Fix build on NetBSD.

--- glib/gthread.c.orig	2024-12-11 22:21:22 UTC
+++ glib/gthread.c
@@ -1147,7 +1147,7 @@ g_get_num_processors (void)
 
   if (count > 0)
     return count;
-#elif defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP)
+#elif defined(_SC_NPROCESSORS_ONLN) && defined(THREADS_POSIX) && defined(HAVE_PTHREAD_GETAFFINITY_NP) && defined(CPU_ZERO)
   {
     int ncores = MIN (sysconf (_SC_NPROCESSORS_ONLN), CPU_SETSIZE);
     cpu_set_t cpu_mask;
