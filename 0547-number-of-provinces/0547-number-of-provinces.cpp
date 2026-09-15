class Solution {
    private:
    void dfs(int i, vector<vector<int>> &adj,vector<int> &vis){
        vis[i] = 1;
        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n+1,0);
        int cnt =0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                cnt++;
            }
        }
        return cnt;
    }
};