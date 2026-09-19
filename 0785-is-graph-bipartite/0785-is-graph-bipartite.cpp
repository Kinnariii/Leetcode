class Solution {
    bool bfs(int node,int colr,vector<int>vis,vector<vector<int>> &graph){
        queue<pair<int,int>>q;
        q.push({node,colr});
        vis[node] = colr;
         while(!q.empty()){
            int node = q.front().first, clr = q.front().second;q.pop();
            for(auto it : graph[node]){
                if(vis[it] == -1){
                    q.push({it,!clr});
                    vis[it] = !clr;
                }
                else if(vis[it] == clr){
                    return false;
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
       
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(bfs(i,0,vis,graph)==false) return false;
        }
        
       
        return true;
    }
};