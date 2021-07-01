/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class LowestCommonAncestor {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        father = new HashMap<Integer, TreeNode>();
        tagNodes = new HashSet<Integer>();
        tagNodes.add(root.val);
        calcFather(root);

        // 遍历p节点的父节点
        while(p.val != root.val){
            tagNodes.add(p.val);
            p = father.get(p.val);
        }
        // 找到q节点的ancestor节点中和p节点的ancestor节点相遇的点，记录后返回
        while(!tagNodes.contains(q.val)){
            q = father.get(q.val);
        }
        return q;
    }

    public void calcFather(TreeNode root){
        if (root == null) return;

        // 左节点的父
        if(root.left != null){
            father.put(root.left.val, root);
            calcFather(root.left);
        }
        // 右节点的父
        if(root.right != null){
            father.put(root.right.val, root);
            calcFather(root.right);
        }
    }

    private Map<Integer, TreeNode> father;
    private Set<Integer> tagNodes;
}