class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n+1, vector<int>(2, -1));
        return solve(prices, 0, 1);
    }
    int solve(vector<int>& nums, int i, int canBuy) {
        if(i >= n) return 0;

        if(dp[i][canBuy] != -1) {
            return dp[i][canBuy];
        }

        if(canBuy) {
            //skip
            int skip = solve(nums, i+1, 1);
            int take = -nums[i] + solve(nums, i+1, 0);
            return dp[i][canBuy] = max(skip, take);
        }

        int sell = nums[i] + solve(nums, i+2, 1);
        int hold = solve(nums, i+1, 0);
        return dp[i][canBuy] = max(sell, hold);
    }
};
