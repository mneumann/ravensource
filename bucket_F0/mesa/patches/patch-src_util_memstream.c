--- src/util/memstream.c.orig	2022-02-09 20:10:39 UTC
+++ src/util/memstream.c
@@ -51,7 +51,7 @@ u_memstream_open(struct u_memstream *mem
    }
 
    return success;
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__sun)
    return false;
 #else
    FILE *const f = open_memstream(bufp, sizep);
