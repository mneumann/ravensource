--- cmake/Macros.cmake.orig	2024-01-04 15:50:46 UTC
+++ cmake/Macros.cmake
@@ -16,10 +16,10 @@ macro(setup_filenames)
         set(DATA_FILEPATH ${CMAKE_CURRENT_SOURCE_DIR}/${DATA_FILE})
         message(STATUS "Using data file ${DATA_FILEPATH} for key ${__KEY}")
     else()
-        file(GLOB DATA_FILEPATHS "${CMAKE_CURRENT_SOURCE_DIR}/${__PREFIX}_2*.txt")
+        file(GLOB DATA_FILEPATHS "${CMAKE_CURRENT_SOURCE_DIR}/${__PREFIX}_*.txt")
         list(SORT DATA_FILEPATHS COMPARE FILE_BASENAME)
         list(POP_BACK DATA_FILEPATHS DATA_FILEPATH)
-        get_filename_component(DATA_FILE ${DATA_FILEPATH} NAME)
+        get_filename_component(DATA_FILE "${DATA_FILEPATH}" NAME)
         message(STATUS "Using present data file '${DATA_FILEPATH}' for key ${__KEY}")
     endif()
     set(DATA_FILEPATH_${__KEY} ${DATA_FILEPATH}  CACHE STRING "raw data file path" FORCE)
