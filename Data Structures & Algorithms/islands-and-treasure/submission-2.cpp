class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int nr = r+dir[i][0];
                int nc = c+dir[i][1];

                if(nc<0 || nc>=m || nr<0 || nr>=n || grid[nr][nc] != INT_MAX) {
                    continue;
                }
                q.push({nr, nc});
                grid[nr][nc] = 1+grid[r][c];
            }
        }
    }
};
