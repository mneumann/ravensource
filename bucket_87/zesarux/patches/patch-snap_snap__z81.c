dummy operation does not even build on DragonFly.
It was there to silence a compiler warning.

--- snap/snap_z81.c.orig	2024-06-06 15:45:53 UTC
+++ snap/snap_z81.c
@@ -284,7 +284,6 @@ void load_snap_ace(FILE *f)
 	//de momento volver sin mas
 	//y que el compilador no se queje de variable no usada
 	f=NULL;
-	f++;
 	return;
 /*
         int puntero_memoria=0x2000;