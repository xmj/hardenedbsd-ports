--- generic/bltDecls.h.orig	2013-11-18 17:41:05.000000000 +0100
+++ generic/bltDecls.h	2013-11-18 17:43:44.000000000 +0100
@@ -532,7 +532,7 @@
 
     Blt_TreeKey (*blt_TreeGetKey) _ANSI_ARGS_((CONST char * string)); /* 0 */
     Blt_TreeNode (*blt_TreeCreateNode) _ANSI_ARGS_((Blt_Tree tree, Blt_TreeNode parent, CONST char * name, int position)); /* 1 */
-    Blt_TreeNode (*blt_TreeCreateNodeWithId) _ANSI_ARGS_((Blt_Tree tree, Blt_TreeNode parent, CONST char * name, int position, int inode)); /* 2 */
+    Blt_TreeNode (*blt_TreeCreateNodeWithId) _ANSI_ARGS_((Blt_Tree tree, Blt_TreeNode parent, CONST char * name, unsigned int position, int inode)); /* 2 */
     int (*blt_TreeDeleteNode) _ANSI_ARGS_((Blt_Tree tree, Blt_TreeNode node)); /* 3 */
     int (*blt_TreeMoveNode) _ANSI_ARGS_((Blt_Tree tree, Blt_TreeNode node, Blt_TreeNode parent, Blt_TreeNode before)); /* 4 */
     Blt_TreeNode (*blt_TreeGetNode) _ANSI_ARGS_((Blt_Tree tree, unsigned int inode)); /* 5 */
@@ -558,7 +558,7 @@
     int (*blt_TreeSetArrayValue) _ANSI_ARGS_((Tcl_Interp * interp, Blt_Tree tree, Blt_TreeNode node, CONST char * arrayName, CONST char * elemName, Tcl_Obj * valueObjPtr)); /* 25 */
     int (*blt_TreeUnsetArrayValue) _ANSI_ARGS_((Tcl_Interp * interp, Blt_Tree tree, Blt_TreeNode node, CONST char * arrayName, CONST char * elemName)); /* 26 */
     int (*blt_TreeArrayValueExists) _ANSI_ARGS_((Blt_Tree tree, Blt_TreeNode node, CONST char * arrayName, CONST char * elemName)); /* 27 */
-    int (*blt_TreeArrayNames) _ANSI_ARGS_((Tcl_Interp * interp, Blt_Tree tree, Blt_TreeNode node, CONST char * arrayName, Tcl_Obj * listObjPtr)); /* 28 */
+    int (*blt_TreeArrayNames) _ANSI_ARGS_((Tcl_Interp * interp, Blt_Tree tree, Blt_TreeNode node, CONST char * arrayName, Tcl_Obj * listObjPtr, const char *)); /* 28 */
     int (*blt_TreeGetValueByKey) _ANSI_ARGS_((Tcl_Interp * interp, Blt_Tree tree, Blt_TreeNode node, Blt_TreeKey key, Tcl_Obj ** valuePtr)); /* 29 */
     int (*blt_TreeSetValueByKey) _ANSI_ARGS_((Tcl_Interp * interp, Blt_Tree tree, Blt_TreeNode node, Blt_TreeKey key, Tcl_Obj * valuePtr)); /* 30 */
     int (*blt_TreeUnsetValueByKey) _ANSI_ARGS_((Tcl_Interp * interp, Blt_Tree tree, Blt_TreeNode node, Blt_TreeKey key)); /* 31 */
@@ -578,13 +578,13 @@
     void (*blt_TreeDeleteTrace) _ANSI_ARGS_((Blt_TreeTrace token)); /* 45 */
     void (*blt_TreeCreateEventHandler) _ANSI_ARGS_((Blt_Tree tree, unsigned int mask, Blt_TreeNotifyEventProc * proc, ClientData clientData)); /* 46 */
     void (*blt_TreeDeleteEventHandler) _ANSI_ARGS_((Blt_Tree tree, unsigned int mask, Blt_TreeNotifyEventProc * proc, ClientData clientData)); /* 47 */
-    void (*blt_TreeRelabelNode) _ANSI_ARGS_((Blt_Tree tree, Blt_TreeNode node, CONST char * string)); /* 48 */
-    void (*blt_TreeRelabelNode2) _ANSI_ARGS_((Blt_TreeNode node, CONST char * string)); /* 49 */
+    int (*blt_TreeRelabelNode) _ANSI_ARGS_((Blt_Tree tree, Blt_TreeNode node, CONST char * string)); /* 48 */
+    int (*blt_TreeRelabelNode2) _ANSI_ARGS_((Blt_TreeNode node, CONST char * string)); /* 49 */
     char * (*blt_TreeNodePath) _ANSI_ARGS_((Blt_TreeNode node, Tcl_DString * resultPtr)); /* 50 */
     int (*blt_TreeNodePosition) _ANSI_ARGS_((Blt_TreeNode node)); /* 51 */
     void (*blt_TreeClearTags) _ANSI_ARGS_((Blt_Tree tree, Blt_TreeNode node)); /* 52 */
-    void (*blt_TreeAddTag) _ANSI_ARGS_((Blt_Tree tree, Blt_TreeNode node, CONST char * tagName)); /* 53 */
-    void (*blt_TreeForgetTag) _ANSI_ARGS_((Blt_Tree tree, CONST char * tagName)); /* 54 */
+    int (*blt_TreeAddTag) _ANSI_ARGS_((Blt_Tree tree, Blt_TreeNode node, CONST char * tagName)); /* 53 */
+    int (*blt_TreeForgetTag) _ANSI_ARGS_((Blt_Tree tree, CONST char * tagName)); /* 54 */
     int (*blt_TreeTagTableIsShared) _ANSI_ARGS_((Blt_Tree tree)); /* 55 */
     int (*blt_TreeShareTagTable) _ANSI_ARGS_((Blt_Tree src, Blt_Tree target)); /* 56 */
     Blt_HashEntry * (*blt_TreeFirstTag) _ANSI_ARGS_((Blt_Tree tree, Blt_HashSearch * searchPtr)); /* 57 */
