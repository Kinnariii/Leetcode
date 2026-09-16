class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int clr = image[sr][sc];
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vector<vector<int>>img = image;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[sr][sc]=1;
        img[sr][sc] = color;
        int row[4] = {-1,0,1,0};
        int col[4] = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first, c = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + row[i], nc = c + col[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && image[nr][nc] == clr && !vis[nr][nc]){
                    img[nr][nc] = color;
                    q.push({nr,nc});
                    vis[nr][nc] = 1;
                }
            }
        }
        return img;
    }
};