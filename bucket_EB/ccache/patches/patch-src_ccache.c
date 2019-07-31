- Don't hash -fcolor-diagnostics; make will auto use it while make -j will not.
  There's no reason to not use the cache in either of these cases if it is
  already available.

--- src/ccache.c.orig	2019-05-01 14:29:07 UTC
+++ src/ccache.c
@@ -1944,6 +1944,7 @@ calculate_common_hash(struct args *args,
 		free(p);
 	}
 
+#if 0
 	// Possibly hash GCC_COLORS (for color diagnostics).
 	if (guessed_compiler == GUESSED_GCC) {
 		const char *gcc_colors = getenv("GCC_COLORS");
@@ -1952,6 +1953,7 @@ calculate_common_hash(struct args *args,
 			hash_string(hash, gcc_colors);
 		}
 	}
+#endif
 }
 
 // Update a hash sum with information specific to the direct and preprocessor
@@ -1988,6 +1990,13 @@ calculate_object_hash(struct args *args,
 			continue;
 		}
 
+		/* Colors do not affect compilation. */
+		if (str_startswith(args->argv[i], "-fcolor-diagnostics") ||
+		    str_eq(args->argv[i], "-fdiagnostics-color") ||
+		    str_eq(args->argv[i], "-fdiagnostics-color=always")) {
+			continue;
+		}
+
 		// The -fdebug-prefix-map option may be used in combination with
 		// CCACHE_BASEDIR to reuse results across different directories. Skip using
 		// the value of the option from hashing but still hash the existence of the
