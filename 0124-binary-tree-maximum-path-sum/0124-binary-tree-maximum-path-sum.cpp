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
    int maxsum(TreeNode* root, int &ans){
        if(root==NULL) {
            return 0;
        }
        int l = max(0,maxsum(root->left,ans));
        int r = max(0,maxsum(root->right,ans));
        int h = l + r + root->val;
        ans = max(ans,h);
        return max(l,r) + root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        maxsum(root,ans);
        return ans;
    }
};