--- ucb/source/ucp/webdav/DateTimeHelper.cxx.orig	2020-08-12 13:23:59 UTC
+++ ucb/source/ucp/webdav/DateTimeHelper.cxx
@@ -17,6 +17,8 @@
  *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
  */
 
+#include <cstdio>
+
 #include <osl/time.h>
 #include <com/sun/star/util/DateTime.hpp>
 #include "DateTimeHelper.hxx"
