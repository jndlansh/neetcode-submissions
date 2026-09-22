class Solution {
public:
    int n, m;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0,  -1}};
    void dfs(vector<vector<int>>& grid, int& currArea, int r, int c) {
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c] == 0){
            return;
        }
        grid[r][c] = 0;
        currArea++;
        for(int i=0; i<4; i++){
            dfs(grid, currArea, r+dir[i][0], c+dir[i][1]);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int maxArea = 0;

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                int currArea = 0;
                if(grid[r][c] == 1){
                    dfs(grid, currArea, r, c);
                    maxArea = max(maxArea, currArea);
                }
            }
        }
        return maxArea;
    }
};
