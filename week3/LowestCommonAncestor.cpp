/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class LowestCommonAncestor {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 向上标记法
        // ANSWER: one of q's ancestor MEETS one of ancestors of p
        unordered_map<int, TreeNode*> father; 
        vector<int> redNodes;
        redNodes.push_back(root->val);
        calcFather(root);
        
        while(p != nullptr && p->val != root->val){
            redNodes.push_back(p->val);
            p = father[p->val];
        }
        while(q != nullptr && !redNodes[q->val]){
            q = father[q->val];
        }
        return q;
    }

    void calcFather(TreeNode* root){
        if (root == nullptr) return;
        if(root->left != nullptr){
            father.insert(make_pair(root->left->val, root));
            calcFather(root->left);
        }
        if(root->right != nullptr){
            father.insert(make_pair(root->right->val, root));
            calcFather(root->right);
        }
    }

private:
    unordered_map<int, TreeNode*> father;
    vector<int> redNodes;
};