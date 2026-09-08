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
public:
    int pre = 0;
    unordered_map<int,int>mpp;
    TreeNode* build(int s,int e,vector<int>& preorder,vector<int>& inorder){
        if(s > e) return NULL;
        int r = preorder[pre++];
        TreeNode* temp = new TreeNode(r);
        int i = mpp[r];
        temp->left = build(s,i-1,preorder,inorder);
        temp->right = build(i+1,e,preorder,inorder);
        return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int n = preorder.size();
       for(int i=0;i<n;i++){
        mpp[inorder[i]] = i;
       }
       TreeNode* ans = build(0,n-1,preorder,inorder);
       return ans;
    }
};