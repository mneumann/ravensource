--- lib/util.c.orig	2023-09-11 01:23:52 UTC
+++ lib/util.c
@@ -1055,6 +1055,7 @@ EXPORTED int parsehex(const char *p, con
 
 /* buffer handling functions */
 
+#undef roundup
 #ifdef HAVE_DECLARE_OPTIMIZE
 static inline size_t roundup(size_t size)
     __attribute__((pure, always_inline, optimize("-O3")));
