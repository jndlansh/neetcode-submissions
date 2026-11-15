class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>>q;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int time = 0;

        while(!q.empty() && fresh>0) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                auto [r, c] = q.front(); q.pop();

                for(int i=0; i<4; i++) {
                    int nr = r+dir[i][0];
                    int nc = c+dir[i][1];

                    if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh ? -1 : time;
    }
};
