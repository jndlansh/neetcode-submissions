class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int r=0; r<n; r++) {
            for(int c=0; c<m; c++) {
                if(grid[r][c] == 0) continue;

                int currArea = 0;
                queue<pair<int, int>>q;
                q.push({r, c});
                grid[r][c] = 0;

                while(!q.empty()) {
                    auto [cr, cc] = q.front();
                    q.pop();

                    currArea++;
                    for(int i=0; i<4; i++) {
                        int nr = cr+dr[i];
                        int nc = cc+dc[i];

                        if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1){
                            grid[nr][nc] = 0;
                            q.push({nr, nc});
                        }
                    }
                }
                maxArea = max(maxArea, currArea);
            }
        }
        return maxArea;
    }
};
