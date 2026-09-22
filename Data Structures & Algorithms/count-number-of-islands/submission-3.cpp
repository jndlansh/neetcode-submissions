class Solution {
public:
    int n, m;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0';

        for(int i=0; i<4; i++){
            dfs(grid, r+dir[i][0], c+dir[i][1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int islands = 0;

        for(int r=0; r<n; r++) {
            for(int c=0; c<m; c++) {
                if(grid[r][c] == '1'){
                    islands++;
                    dfs(grid, r, c);
                }
            }
        }
        return islands;
    }
};
