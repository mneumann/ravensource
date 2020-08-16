--- config/defaults.inc.php.orig	2020-08-10 19:04:57 UTC
+++ config/defaults.inc.php
@@ -801,8 +801,8 @@ $config['spellcheck_dictionary'] = false
 // You can connect to any other googie-compliant service by setting 'spellcheck_uri' accordingly.
 $config['spellcheck_engine'] = 'googie';
 
-// For locally installed Nox Spell Server or After the Deadline services,
-// please specify the URI to call it.
+// For a locally installed spellcheker, specify the URI to call it, for example:
+// 'http://' . $_SERVER['HTTP_HOST'] . '/spellchecker.php?lang='
 // Get Nox Spell Server from http://orangoo.com/labs/?page_id=72 or
 // the After the Deadline package from http://www.afterthedeadline.com.
 // Leave empty to use the public API of service.afterthedeadline.com
