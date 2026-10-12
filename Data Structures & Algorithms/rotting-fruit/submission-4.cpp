class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q;
        int fresh = 0;

        for(int r=0; r<n; r++) {
            for(int c=0; c<m; c++) {
                if(grid[r][c]==2) {
                    q.push({r, c});
                } else if(grid[r][c] == 1) {
                    fresh++;
                }
            }
        }

        int time = 0;
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty() && fresh) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                auto [r, c] = q.front(); q.pop();
                
                for(int i=0; i<4; i++) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];

                    if(nr<0 || nr>=n || nc<0 || nc>=m || grid[nr][nc]!=1) {
                        continue;
                    }
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh--;
                }
            }
            time++;
        }
        return fresh ? -1 : time;
    }
};
