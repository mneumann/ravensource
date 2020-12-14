--- dragonflybsd/Platform.c.orig	2020-12-07 00:49:14 UTC
+++ dragonflybsd/Platform.c
@@ -210,9 +210,23 @@ void Platform_setSwapValues(Meter* this)
 }
 
 char* Platform_getProcessEnv(pid_t pid) {
-   // TODO
-   (void)pid;  // prevent unused warning
-   return NULL;
+   char *env = NULL, **fenv = NULL, *ptr = NULL;
+   size_t size = 0;
+
+   fenv = DragonFlyBSDGet_env(pid);
+
+   if (fenv) {
+      ptr = fenv[0];
+      while (ptr && *ptr) {
+         size += strlen(ptr) + 1;
+         ptr += strlen(ptr) + 1;
+      }
+      env = xMalloc(size+2);
+      memcpy(env, fenv[0], size);
+      env[size] = 0;
+      env[size+1] = 0;
+   }
+   return env;
 }
 
 char* Platform_getInodeFilename(pid_t pid, ino_t inode) {
