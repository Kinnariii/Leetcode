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
class Solution {
    bool Sym(TreeNode* p,TreeNode* q){
        if(p ==NULL && q == NULL){
            return true;
        }
        if(p==NULL || q==NULL) return false;
        bool l = Sym(p->left,q->right);
        bool r = Sym(p->right,q->left);
        bool v = p->val == q->val;
        if(l && r && v) return true;
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return Sym(root->left,root->right);
    }
};