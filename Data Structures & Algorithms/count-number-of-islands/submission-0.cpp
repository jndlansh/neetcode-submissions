class Solution {
public:
    bool dfs(vector<vector<char>>& grid, int r, int c) {
        int n = grid.size();
        int m = grid[0].size();
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]=='0') {
            return false;
        }

        grid[r][c] = '0';

        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);

        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands=0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dfs(grid, i, j)) {
                    islands++;
                }
            }
        }
        return islands;
    }
};
