--- sapi/apache2handler/config.m4.orig	2021-06-29 09:30:32 UTC
+++ sapi/apache2handler/config.m4
@@ -65,7 +65,7 @@ if test "$PHP_APXS2" != "no"; then
   fi
 
   APXS_LIBEXECDIR='$(INSTALL_ROOT)'`$APXS -q LIBEXECDIR`
-  if test -z `$APXS -q SYSCONFDIR`; then
+  if true; then
     INSTALL_IT="\$(mkinstalldirs) '$APXS_LIBEXECDIR' && \
                  $APXS -S LIBEXECDIR='$APXS_LIBEXECDIR' \
                        -i -n php7"
