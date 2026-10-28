class Solution {
public:
    int n1, n2;
    vector<vector<int>>dp;
    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.size(), n2 = text2.size();
        dp.assign(n1+1, vector<int>(n2+1, -1));
        return solve(text1, text2, 0, 0);
    }
    int solve(string text1, string text2, int i, int j) {
        if(i>=n1 || j>=n2) {
            return 0;
        }

        if(dp[i][j]!=-1) {
            return dp[i][j];
        }

        if(text1[i]==text2[j]) {
            return dp[i][j] = 1+solve(text1, text2, i+1, j+1);
        }
        return dp[i][j] = max(solve(text1, text2, i+1, j), solve(text1, text2, i, j+1));
    }
};
