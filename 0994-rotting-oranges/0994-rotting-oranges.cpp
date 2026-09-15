class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;

        // Put all initially rotten oranges into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (fresh == 0)
            return 0;

        int time = 0;

        int row[4] = {-1, 0, 1, 0};
        int col[4] = {0, 1, 0, -1};

        while (!q.empty()) {

            int size = q.size();
            bool rotted = false;

            // Process all oranges that are rotten
            // at the beginning of this minute
            while (size--) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int nr = r + row[i];
                    int nc = c + col[i];

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        grid[nr][nc] == 1) {

                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                        rotted = true;
                    }
                }
            }

            if (rotted)
                time++;
        }

        if (fresh != 0)
            return -1;

        return time;
    }
};