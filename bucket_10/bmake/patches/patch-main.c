--- main.c.orig	2023-02-25 20:04:29 UTC
+++ main.c
@@ -1427,6 +1427,12 @@ main_Init(int argc, char **argv)
 		Global_Set_ReadOnly(".MAKE.UID", buf);
 		snprintf(buf, sizeof buf, "%u", getgid());
 		Global_Set_ReadOnly(".MAKE.GID", buf);
+		Global_Set_ReadOnly(".MAKE.OS.NAME",          OSNAME);
+		Global_Set_ReadOnly(".MAKE.OS.VERSION",       OSVERSION);
+		Global_Set_ReadOnly(".MAKE.OS.RELEASE",       OSRELEASE);
+		Global_Set_ReadOnly(".MAKE.OS.MAJOR",         OSMAJOR);
+		Global_Set_ReadOnly(".MAKE.OS.ARCHITECTURE",  OSARCH);
+		Global_Set_ReadOnly(".MAKE.OS.ARCH.STANDARD", STDARCH);
 	}
 	if (makelevel > 0) {
 		char pn[1024];
