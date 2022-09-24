--- src/idn2.c.orig	2021-07-19 18:03:51 UTC
+++ src/idn2.c
@@ -33,7 +33,7 @@
 #include <unistring/localcharset.h>
 
 /* Gnulib headers. */
-#include "error.h"
+#include "err.h"
 #include "gettext.h"
 #define _(String) dgettext (PACKAGE, String)
 #include "progname.h"
@@ -182,7 +182,7 @@ process_input (char *readbuf, int flags)
       free (output);
     }
   else
-    error (EXIT_FAILURE, 0, "%s: %s", tag, idn2_strerror (rc));
+    errc (EXIT_FAILURE, 0, "%s: %s", tag, idn2_strerror (rc));
 }
 
 int
@@ -249,7 +249,7 @@ main (int argc, char *argv[])
     }
 
   if (ferror (stdin))
-    error (EXIT_FAILURE, errno, "%s", _("input error"));
+    errc (EXIT_FAILURE, errno, "%s", _("input error"));
 
   cmdline_parser_free (&args_info);
 
