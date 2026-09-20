class Solution {
public:
    int n, m;
    void dfs(vector<vector<int>>& grid, int r, int c, int& len) {
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]==0){
            return;
        }
        grid[r][c] = 0;
        len++;
        
        dfs(grid, r+1, c, len);
        dfs(grid, r-1, c, len);
        dfs(grid, r, c+1, len);
        dfs(grid, r, c-1, len);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int area = 0;
        

        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(grid[r][c] == 1){
                    int len = 0;
                    dfs(grid, r, c, len);
                    area = max(len, area);
                }
            }
        }
        return area;
    }
};
