--- scheduler/subscriptions.c.orig	2024-04-26 11:38:21 UTC
+++ scheduler/subscriptions.c
@@ -1521,8 +1521,8 @@ cupsd_start_notifier(
   * Create the notifier process...
   */
 
-  if (cupsdStartProcess(command, argv, envp, fds[0], -1, NotifierPipes[1],
-			-1, -1, 0, DefaultProfile, NULL, &pid) < 0)
+  if (!cupsdStartProcess(command, argv, envp, fds[0], -1, NotifierPipes[1],
+			 -1, -1, 0, DefaultProfile, NULL, &pid))
   {
    /*
     * Error - can't fork!
