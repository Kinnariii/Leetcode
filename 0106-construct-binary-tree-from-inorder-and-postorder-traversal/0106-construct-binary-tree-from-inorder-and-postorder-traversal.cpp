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
unordered_map<int,int>mpp;

    TreeNode* build(int s,int e,vector<int>& postorder,vector<int>& inorder,int &p){
        if(s > e) return NULL;
        int r = postorder[p--];
        int i = mpp[r];
        TreeNode* temp = new TreeNode(r);
        temp->right = build(i+1,e,postorder,inorder,p);
        temp->left = build(s,i-1,postorder,inorder,p);
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n==0) return NULL;
        for(int i=0;i<n;i++){
            mpp[inorder[i]] = i;
        }
        int p = n-1;
        TreeNode* ans = build(0,n-1,postorder,inorder,p);
        return ans;
    }
};