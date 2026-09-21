class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh=0;
        
        for(int r=0; r<n; r++) {
            for(int c=0; c<m; c++) {
                if(grid[r][c] == 2) {
                    q.push({r,c});
                }
                else if(grid[r][c] == 1) {
                    fresh++;
                }
            }
        }
        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int time=0;
        while(!q.empty() && fresh>0) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                auto [r, c] = q.front(); q.pop();

                for(int d=0; d<4; d++) {
                    int nr = r+dir[d][0];
                    int nc = c+dir[d][1];

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
        return fresh == 0 ? time : -1;
    }
};
