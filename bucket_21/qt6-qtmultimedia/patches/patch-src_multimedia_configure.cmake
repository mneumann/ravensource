--- src/multimedia/configure.cmake.orig	2024-03-25 10:03:22 UTC
+++ src/multimedia/configure.cmake
@@ -76,7 +76,7 @@ qt_feature("ffmpeg" PRIVATE
     LABEL "FFmpeg"
     ENABLE INPUT_ffmpeg STREQUAL 'yes'
     DISABLE INPUT_ffmpeg STREQUAL 'no'
-    CONDITION FFmpeg_FOUND AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_pulseaudio)
+    CONDITION FFmpeg_FOUND AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_alsa OR QT_FEATURE_pulseaudio)
 )
 qt_feature("alsa" PUBLIC PRIVATE
     LABEL "ALSA (experimental)"
