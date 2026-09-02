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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        map<int, int>mpp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int row = q.front().second;
            q.pop();
            mpp[row] = temp->val;
            if(temp->left){
                q.push({temp->left,row+1});
            }
            if(temp->right){
                q.push({temp->right,row+1});
            }
        }
        for(auto i : mpp){
            ans.push_back(i.second);
        }
        return ans;
    }
};