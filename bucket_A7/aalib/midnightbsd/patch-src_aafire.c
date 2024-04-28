--- src/aafire.c.orig	2001-04-26 15:30:03 UTC
+++ src/aafire.c
@@ -48,6 +48,7 @@ static void
 initialize (void)
 {
   int i;
+  srandomdev();
   context = aa_autoinit (&aa_defparams);
   if (context == NULL)
     {
@@ -114,20 +115,20 @@ drawfire (void)
   height++;
   loop--;
   if (loop < 0)
-    loop = rand () % 3, sloop++;;
+    loop = random () % 3, sloop++;;
   i1 = 1;
   i2 = 4 * XSIZ + 1;
   for (p = (char *) bitmap + XSIZ * (YSIZ + 0);
        p < ((unsigned char *) bitmap + XSIZ * (YSIZ + 1));
        p++, i1 += 4, i2 -= 4)
     {
-      last1 = rand () % min (i1, min (i2, height));
-      i = rand () % 6;
+      last1 = random () % min (i1, min (i2, height));
+      i = random () % 6;
       for (; p < (unsigned char *) bitmap + XSIZ * (YSIZ + 1) && i != 0;
 	   p++, i--, i1 += 4, i2 -= 4)
-	*p = last1, last1 += rand () % 6 - 2, *(p + XSIZ) = last1, last1 +=
-	  rand () % 6 - 2;
-      *(p + 2 * XSIZ) = last1, last1 += rand () % 6 - 2;
+	*p = last1, last1 += random () % 6 - 2, *(p + XSIZ) = last1, last1 +=
+	  random () % 6 - 2;
+      *(p + 2 * XSIZ) = last1, last1 += random () % 6 - 2;
     }
   i = 0;
   firemain ();
