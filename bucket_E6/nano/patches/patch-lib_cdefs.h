--- lib/cdefs.h.orig	2020-07-29 08:05:10 UTC
+++ lib/cdefs.h
@@ -292,7 +292,7 @@
    for portability when this file is used in Gnulib.  */
 #ifndef __nonnull
 # if __GNUC_PREREQ (3,3)
-#  define __nonnull(params) __attribute__ ((__nonnull__ params))
+#  define __nonnull(params) __attribute__ ((__nonnull__ (params)))
 # else
 #  define __nonnull(params)
 # endif
