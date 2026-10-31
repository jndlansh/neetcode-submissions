class Solution {
public:
    vector<int>dp;
    int n;
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        dp.assign(n+1, -1);
        return min(solve(cost, 0), solve(cost, 1));
    }
    int solve(vector<int>& nums, int i) {
        if( i >= n) return 0;

        if(dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = nums[i] + min(solve(nums, i+1), solve(nums, i+2));
    }
};
