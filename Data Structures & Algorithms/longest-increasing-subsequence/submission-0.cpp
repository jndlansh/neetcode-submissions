class Solution {
public:
    vector<vector<int>>dp;
    int n;
    int dfs(vector<int>& nums, int i, int j) {
        if(i == n) {
            return 0;
        }
        if(dp[i][j+1] != -1) {
            return dp[i][j+1];
        }

        int LIS = dfs(nums, i+1, j);

        if(j==-1 || nums[j] < nums[i]) {
            LIS = max(LIS, 1+dfs(nums, i+1, i));
        }
        dp[i][j+1] = LIS;
        return LIS;
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n + 1, -1));
        return dfs(nums, 0, -1);
    }
};
