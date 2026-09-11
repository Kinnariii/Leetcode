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
    int pre = 0;
    TreeNode* solve(int s,int e,vector<int>& preorder,vector<int>& inorder){
      if(s>e) return NULL;
      int v = preorder[pre++];
      TreeNode* temp = new TreeNode(v);
      int ind = mpp[v];
      temp->left = solve(s,ind-1,preorder,inorder);
      temp->right = solve(ind+1,e,preorder,inorder);
      return temp;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0) return NULL;
        vector<int> inorder;
        for(auto i : preorder){
            inorder.push_back(i);
        }
        sort(inorder.begin(),inorder.end());
        int n = preorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]] = i;
        }
        return solve(0,n-1,preorder,inorder);
    }
};