--- sendrecvmsg.c.orig	2021-07-29 12:53:58 UTC
+++ sendrecvmsg.c
@@ -23,6 +23,9 @@
 #ifdef ZTS
 #include <TSRM/TSRM.h>
 #endif
+#ifdef __DragonFly__
+#include <sys/ucred.h>
+#endif
 
 #define MAX_USER_BUFF_SIZE ((size_t)(100*1024*1024))
 #define DEFAULT_BUFF_SIZE 8192
@@ -121,8 +124,13 @@ static void init_ancillary_registry(void
 #endif
 
 #ifdef SO_PASSCRED
+#if !defined(__DragonFly__)
 	PUT_ENTRY(sizeof(struct ucred), 0, 0, from_zval_write_ucred,
 			to_zval_read_ucred, SOL_SOCKET, SCM_CREDENTIALS);
+#else
+	PUT_ENTRY(sizeof(struct cmsgcred), 0, 0, from_zval_write_ucred,
+			to_zval_read_ucred, SOL_SOCKET, SCM_CREDS);
+#endif	
 #endif
 
 #ifdef SCM_RIGHTS
@@ -436,7 +444,11 @@ void php_socket_sendrecvmsg_init(INIT_FU
 	REGISTER_LONG_CONSTANT("SCM_RIGHTS",			SCM_RIGHTS,			CONST_CS | CONST_PERSISTENT);
 #endif
 #ifdef SO_PASSCRED
+#if !defined(__DragonFly__)
 	REGISTER_LONG_CONSTANT("SCM_CREDENTIALS",		SCM_CREDENTIALS,	CONST_CS | CONST_PERSISTENT);
+#else
+	REGISTER_LONG_CONSTANT("SCM_CREDS",			SCM_CREDS,		CONST_CS | CONST_PERSISTENT);
+#endif
 	REGISTER_LONG_CONSTANT("SO_PASSCRED",			SO_PASSCRED,		CONST_CS | CONST_PERSISTENT);
 #endif
 
