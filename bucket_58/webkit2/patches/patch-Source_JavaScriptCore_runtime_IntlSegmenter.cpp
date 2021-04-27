--- Source/JavaScriptCore/runtime/IntlSegmenter.cpp.orig	2021-02-26 09:57:05 UTC
+++ Source/JavaScriptCore/runtime/IntlSegmenter.cpp
@@ -125,7 +125,7 @@ JSValue IntlSegmenter::segment(JSGlobalO
     auto upconvertedCharacters = Box<Vector<UChar>>::create(string.charactersWithoutNullTermination());
 
     UErrorCode status = U_ZERO_ERROR;
-    auto segmenter = std::unique_ptr<UBreakIterator, UBreakIteratorDeleter>(ubrk_safeClone(m_segmenter.get(), nullptr, nullptr, &status));
+    auto segmenter = std::unique_ptr<UBreakIterator, UBreakIteratorDeleter>(ubrk_clone(m_segmenter.get(), &status));
     if (U_FAILURE(status)) {
         throwTypeError(globalObject, scope, "failed to initialize Segments"_s);
         return { };
