/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class InorderSuccessor {
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        return findSuccessor(root, p.val);
    }
    private TreeNode findSuccessor(TreeNode root, int val){
        TreeNode curr = root;
        TreeNode ans = null;;
        while(curr != null){
            if(curr.val > val){
                if(ans == null || ans.val > curr.val) ans = curr;  // 更新答案
            }
            if(curr.val == val){
                if(curr.right != null){  // 找后继
                    curr = curr.right;
                    while(curr.left != null) curr = curr.left;
                    return curr;
                }
                break;
            }
            
            if(val < curr.val) curr = curr.left;
            else curr = curr.right;
        }
        return ans;
    }
}