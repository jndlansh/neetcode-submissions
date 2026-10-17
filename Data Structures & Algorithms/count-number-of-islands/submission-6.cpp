class Solution {
public:
    int n, m;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j] != '1') {
            return;
        } 
        grid[i][j] = '0';
        for(int d=0; d<4; d++) {
            int nr = i+dir[d][0];
            int nc = j+dir[d][1];
            dfs(grid, nr, nc);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int islands = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
};
