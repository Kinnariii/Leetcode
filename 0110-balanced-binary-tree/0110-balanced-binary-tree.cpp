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
    pair<bool,int> balance(TreeNode* root){
        if(root == nullptr){
           pair<bool,int>p = make_pair(true,0);
           return p;
        }
        auto[lb,lh] = balance(root->left);
        auto[rb,rh] = balance(root->right);
        pair<bool,int>ans;
        ans.first = lb && rb && abs(lh-rh) <=1;
        ans.second = max(lh,rh) + 1;
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return balance(root).first;
    }
};