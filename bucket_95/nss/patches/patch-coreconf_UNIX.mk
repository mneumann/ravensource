--- coreconf/UNIX.mk.orig	2020-10-16 14:50:49 UTC
+++ coreconf/UNIX.mk
@@ -10,10 +10,8 @@ AR          = ar cr $@
 LDOPTS     += -L$(SOURCE_LIB_DIR)
 
 ifdef BUILD_OPT
-	OPTIMIZER  += -O
 	DEFINES    += -UDEBUG -DNDEBUG
 else
-	OPTIMIZER  += -g
 	DEFINES    += -DDEBUG -UNDEBUG
 endif
 
