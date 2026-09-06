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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        long long ans = LLONG_MIN,l=0,f=0;
        while(!q.empty()){
            long long mini = q.front().second;
            int size = q.size();
            for(int i=0;i<size;i++){
                long long cur = q.front().second - mini;
                TreeNode* temp = q.front().first;
                q.pop();
                if(temp->left) q.push({temp->left,2*cur+1});
                if(temp->right) q.push({temp->right,2*cur+2});
                if(i==0) l = cur;
                if(i== size-1) f = cur;
            }
            ans = max(ans,f-l+1);
        }
        return ans;
    }
};