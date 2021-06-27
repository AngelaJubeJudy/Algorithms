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
class TreeMaxDepth2 {
    public int maxDepth(TreeNode root) {
        depth = 1;
        ans = 0;
        calc(root);
        return ans;
    }

    private int calc(TreeNode root){
        if(root == null) return 1;
        ans = Math.max(ans, depth);
        depth++;
        calc(root.left);
        calc(root.right);
        depth--;
        return depth;
    }
    private int depth;
    private int ans;

}