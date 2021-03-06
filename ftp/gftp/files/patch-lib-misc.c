Fix segmentation fault, when gftpui_run_chdir is called with directory=0x0,
and then calls gftp_expand_path (src=0x0), 
the NULL string was cloned using g_strdup, which returns NULL if 
its only argument is NULL, then this returned string was unreferenced.

 lib/misc.c |    2 ++
 1 files changed, 2 insertions(+), 0 deletions(-)

diff --git a/lib/misc.c b/lib/misc.c
index 16c019b..2791466 100644
--- lib/misc.c.orig
+++ lib/misc.c
@@ -143,6 +143,8 @@ gftp_expand_path (gftp_request * request, const char *src)
        tempchar;
   struct passwd *pw;
 
+  g_return_val_if_fail(src != NULL, NULL);
+
   pw = NULL;
   str = g_strdup (src);
 
