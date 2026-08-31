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
    private:
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int l = height(root->left);
        int r = height(root->right);
        int h = max(l,r) + 1;
        return h;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        int h =  height(root->left) + height(root->right);
        return max(max(l,r),h);
    }
};