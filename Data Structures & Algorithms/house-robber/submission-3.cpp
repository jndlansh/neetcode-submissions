class Solution {
public:
    int N;
    vector<int>dp;
    int rob(vector<int>& nums) {
        N = nums.size();
        dp.assign(N+1, -1);
        return solve(nums, 0);
    }
    int solve(vector<int>& nums, int n) {
        if(n >= N) return 0;

        if(dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = max(nums[n]+solve(nums, n+2), solve(nums, n+1));
    }
};
