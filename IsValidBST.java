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
class IsValidBST {
    public boolean isValidBST(TreeNode root) {
        // 验证一：是否是二叉搜索树
        // 验证二：左子树（最大节点）都更小
        // 验证三：右子树（最小节点）都更大
        return check(root).isValid;
    }

    private class TmpInfo{
        public boolean isValid;
        public long minVal;
        public long maxVal;
    }

    /* 验证二：左子树（最大节点）都更小
       验证三：右子树（最小节点）都更大
       */
    private TmpInfo check(TreeNode root){
        if (root == null){
            TmpInfo info = new TmpInfo();
            info.isValid = true;
            info.minVal = (long)Integer.MAX_VALUE + 1L;
            info.maxVal = (long)Integer.MIN_VALUE - 1L;
            return info;
        }

        TmpInfo l = check(root.left);
        TmpInfo r = check(root.right);
        TmpInfo result = new TmpInfo();

        if (l.isValid && r.isValid && l.maxVal < root.val && r.minVal > root.val) result.isValid = true;
        else result.isValid = false;

        result.minVal = Math.min(root.val, Math.min(l.minVal, r.minVal));
        result.maxVal = Math.max(root.val, Math.max(l.maxVal, r.maxVal));
        return result;
    }
}