class Solution {
public:
    int n, m;
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]=='0') {
            return;
        }

        grid[r][c] = '0';

        dfs(grid, r+1, c);
        dfs(grid, r-1, c);
        dfs(grid, r, c+1);
        dfs(grid, r, c-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int islands=0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((grid[i][j] == '1')) {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};
