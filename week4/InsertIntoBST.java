/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class InsertIntoBST {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        // 边界
        if(root == null) return new TreeNode(val);

        // 递归
        if(val < root.val) root.left = insertIntoBST(root.left, val);
        else root.right = insertIntoBST(root.right, val);

        return root;
    }
}
