--- bindings/python/setup.py.orig	2024-07-29 07:08:58 UTC
+++ bindings/python/setup.py
@@ -2,10 +2,7 @@
 import os
 import sys
 
-try:
-    from setuptools import setup, Extension
-except ImportError:
-    sys.exit('The setup requires setuptools.')
+from distutils.core import setup, Extension
 
 TOP_SRCDIR = os.environ.get('ABS_TOP_SRCDIR', '../..')
 TOP_BUILDDIR = os.environ.get('ABS_TOP_BUILDDIR', '../..')
