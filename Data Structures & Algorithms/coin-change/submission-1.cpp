class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int target, int i) {
        if(target == 0) {
            return 0;
        }
        if(i >= n) {
            return 1e9;
        }
        if(dp[i][target]!=-1) {
            return dp[i][target];
        }
        int take = 1e9;
        if(nums[i] <= target) {
            take = 1+solve(nums, target-nums[i], i);
        }
        int notTake = solve(nums, target, i+1);

        return dp[i][target] = min(take, notTake);
    }
    int coinChange(vector<int>& nums, int amount) {
        n = nums.size();
        dp.assign(n, vector<int>(amount + 1, -1));

        int ans = solve(nums, amount, 0);
        return ans >= 1e9 ? -1 : ans;
    }
};
