Do not generate debugging symbols (uses lots of disk space).

--- node_modules/node-gyp/gyp/pylib/gyp/xcode_emulation.py.orig	2021-11-04 20:19:11 UTC
+++ node_modules/node-gyp/gyp/pylib/gyp/xcode_emulation.py
@@ -607,7 +607,7 @@ class XcodeSettings:
 
         self._Appendf(cflags, "GCC_OPTIMIZATION_LEVEL", "-O%s", default="s")
 
-        if self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="YES"):
+        if self._Test("GCC_GENERATE_DEBUGGING_SYMBOLS", "YES", default="NO"):
             dbg_format = self._Settings().get("DEBUG_INFORMATION_FORMAT", "dwarf")
             if dbg_format == "dwarf":
                 cflags.append("-gdwarf-2")
