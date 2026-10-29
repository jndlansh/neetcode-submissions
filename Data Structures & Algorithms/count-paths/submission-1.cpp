class Solution {
public:
    vector<vector<int>>dp;
    int uniquePaths(int m, int n) {
        dp.assign(m+1, vector<int>(n+1, -1));
        return solve(m, n, 0, 0);
    }
    int solve(int m, int n, int i, int j) {
        if(i == m-1 && j == n-1) {
            return 1;
        }
        if( i>=m || j >=n ) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        return dp[i][j] = solve(m, n, i+1, j) + solve(m, n, i, j+1);
    }
};
