--- pty_termios.c.orig	2018-02-02 19:15:52 UTC
+++ pty_termios.c
@@ -77,6 +77,14 @@ with openpty which supports 4000 while p
 #include <sys/sysmacros.h>
 #endif
 
+#ifdef HAVE_OPENPTY
+# ifdef __linux__
+# include <pty.h>
+# else
+# include <util.h>
+# endif
+#endif
+
 #ifdef HAVE_PTYTRAP
 #include <sys/ptyio.h>
 #endif
@@ -102,6 +110,7 @@ with openpty which supports 4000 while p
 #include "exp_tty_in.h"
 #include "exp_rename.h"
 #include "exp_pty.h"
+#include "exp_int.h"
 
 void expDiagLog();
 void expDiagLogPtr();
