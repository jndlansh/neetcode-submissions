class Solution {
public:
    int n;
    vector<int>dp;
    int rob(vector<int>& nums) {
        n = nums.size();
        dp.assign(n+1, -1);
        return solve(nums, 0);
    }
    int solve(vector<int>& nums, int i) {
        if(i >= n) return 0;
        if(dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = max(nums[i]+solve(nums, i+2), solve(nums, i+1));
    }
};
