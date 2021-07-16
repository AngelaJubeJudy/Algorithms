/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BuildTree {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // 每一步的思路：
        // 前序：告诉root，不知左右
        // 中序：根据root划分左右子树
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, 
                     int l1, int r1, int l2, int r2){
        //闭区间
        // 边界
        if(l1 > r1) return nullptr;

        TreeNode* root = new TreeNode(preorder[l1]);
        int mid = l2;

        // 确定根的位置
        while(inorder[mid] != root->val) mid++;
        int leftsize = mid - l2;
        root->left = build(preorder, inorder, l1+1, l1+leftsize, l2, mid-1);
        root->right = build(preorder, inorder, l1+leftsize+1, r1, mid+1, r2);
        return root;
    }
};