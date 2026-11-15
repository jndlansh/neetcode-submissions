class Solution {
public:
    int n, m;
    vector<vector<int>>dir={{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == '1') {
                    solve(grid, i, j);
                    ans+=1;
                }
            }
        }
        return ans;
    }
    void solve(vector<vector<char>>& grid, int r, int c) {
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]=='0') {
            return;
        }
        grid[r][c] = '0';

        for(int i=0; i<4; i++) {
            int nr = r+dir[i][0];
            int nc = c+dir[i][1];
            solve(grid, nr, nc);
        }
    }
};
