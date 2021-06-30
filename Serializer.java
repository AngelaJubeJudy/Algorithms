/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Serializer {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        seq = new ArrayList<String>();
        traverse(root);
        return String.join(" ", seq);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        seq = Arrays.asList(data.split(" "));
        currencies = 0;
        return calc();
    }

    private void traverse(TreeNode root){
        if (root == null){
            seq.add("null");
            return;
        }
        seq.add(Integer.toString(root.val));
        traverse(root.left);
        traverse(root.right);
    }

    public TreeNode calc(){
        if(seq.get(currencies).equals("null")){
            currencies++;
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(seq.get(currencies)));
        currencies++;
        root.left = calc();
        root.right = calc();
        return root;
    }

    private List<String> seq;
    private int currencies;
}

// Your Codec object will be instantiated and called as such:
// Codec ser = new Codec();
// Codec deser = new Codec();
// TreeNode ans = deser.deserialize(ser.serialize(root));