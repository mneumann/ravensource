--- svtools/source/svrtf/parrtf.cxx.orig	2023-09-06 15:37:46 UTC
+++ svtools/source/svrtf/parrtf.cxx
@@ -51,6 +51,7 @@ SvRTFParser::~SvRTFParser()
 {
 }
 
+#include <cstdio>
 
 int SvRTFParser::GetNextToken_()
 {
