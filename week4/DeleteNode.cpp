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
class DeleteNode {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(root->val == key){
            // 情况一：leaf节点 / 只有一个子节点的节点————可以直接删除
            if(root->left == nullptr) return root->right;
            if(root->right == nullptr) return root->left;

            // 情况二：`有两个子节点`————找到`后继节点`（右子树可以保持不变），后继节点`一定`没有左子树，因此用`右子树`代替
            TreeNode* next = root->right;
            while(next->left != nullptr) next = next->left;
            root->right = deleteNode(root->right, next->val);
            root->val = next->val;
        }
        if(root->val > key){
            root->left = deleteNode(root->left, key);
        }else{
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
