class Solution {
public: 
    int n, m;
    // int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>&vis, int r, int c, int t) {
        if(r<0 || r>=n || c<0 || c>=m || vis[r][c] || grid[r][c]>t) {
            return false;
        }

        if(r==n-1 && c==m-1) return true;

        vis[r][c] = true;

        return dfs(grid, vis, r + 1, c, t) ||
               dfs(grid, vis, r - 1, c, t) ||
               dfs(grid, vis, r, c + 1, t) ||
               dfs(grid, vis, r, c - 1, t);
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>>vis(n, vector<bool>(m, false));
        int minH = grid[0][0], maxH = grid[0][0];
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                minH = min(minH, grid[i][j]);
                maxH = max(maxH, grid[i][j]);
            }
        }

        for(int t=minH; t<maxH; t++) {
            if(dfs(grid, vis, 0, 0, t)) {
                return t;
            }
            for(int r=0; r<n; r++) {
                fill(vis[r].begin(), vis[r].end(), false);
            }
        }

        // int l=minH, r=maxH;
        // while(l<r) {
        //     int mid = l+(r-l)/2;
        //     if(dfs(grid, vis, 0, 0, mid)) {
        //         r = mid;
        //     } else {
        //         l = mid+1;
        //     }
        //     for(int r=0; r<n; r++) {
        //         fill(vis[r].begin(), vis[r].end(), false);
        //     }
        // }
        // return r;
        return maxH;
    }
};
