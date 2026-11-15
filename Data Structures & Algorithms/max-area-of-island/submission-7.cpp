class Solution {
public:
    int n, m;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxArea = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    int currArea = 0;
                    solve(grid, i, j, currArea);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
    void solve(vector<vector<int>>& grid, int r, int c, int& currArea) {
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]==0) {
            return;
        }
        currArea++;
        grid[r][c] = 0;
        for(int i=0; i<4; i++) {
            int nr = r+dir[i][0];
            int nc = c+dir[i][1];
            solve(grid, nr, nc, currArea);
        }
    }
};
