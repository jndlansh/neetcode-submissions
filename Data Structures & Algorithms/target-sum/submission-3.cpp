class Solution {
public:
    int n, total;
    vector<vector<int>>dp;
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        total = accumulate(nums.begin(), nums.end(), 0);
        dp.assign(n+1, vector<int>(2*total+1, -1));
        return solve(nums, target, 0, 0);
    }
    int solve(vector<int>& nums, int target, int sum, int i) {
        if( i == n) {
            return target == sum;
        }
        if(dp[i][sum+total] != -1) {
            return dp[i][sum+total];
        }
        int negative = solve(nums, target, sum-nums[i], i+1);
        int positive = solve(nums, target, sum+nums[i], i+1);
        return dp[i][sum+total] = negative+positive;
    }
};
