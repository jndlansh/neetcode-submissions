class Solution {
public:
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int n, m;
    void dfs(vector<vector<int>>& grid, int r, int c, int& currArea) {
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]!=1) {
            return;
        }
        grid[r][c] = 0;
        currArea++;

        for(int i=0; i<4; i++) {
            dfs(grid, r+dir[i][0], c+dir[i][1], currArea);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxArea = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int currArea = 0;
                if(grid[i][j] == 1) {
                    dfs(grid, i, j, currArea);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};
