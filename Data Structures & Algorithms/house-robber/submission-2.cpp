class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);

        return solve(nums, dp, 0, n);
    }
    int solve(vector<int>& nums, vector<int>& dp, int i, int n) {
        if(i >= n) return 0;

        if(dp[i]!=-1) {
            return dp[i];
        }

        return dp[i] = max(solve(nums, dp, i+1, n), nums[i] + solve(nums, dp, i+2, n));
    }
};
