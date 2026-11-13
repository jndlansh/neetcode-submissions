class Solution {
public:
    int n, m;
    vector<vector<int>>dp;
    vector<vector<int>>dir={{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int longestIncreasingPath(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        dp.assign(n, vector<int>(m, -1));
        int ans = 1;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans = max(ans, solve(mat, i, j));
            }
        }
        return ans;
    }
    int solve(vector<vector<int>>& mat, int r, int c) {
        if(dp[r][c] != -1) {
            return dp[r][c];
        }
        int best = 1;
        for(int i=0; i<4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]>mat[r][c]) {
                best = max(best, 1+solve(mat, nr, nc));
            }
        }
        return dp[r][c] = best;
    }
};
