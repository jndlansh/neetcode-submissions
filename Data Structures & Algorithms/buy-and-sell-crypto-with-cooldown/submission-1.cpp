class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.assign(n+1, vector<int>(2, -1)); // we have 2 options (canBuy, cannotBuy)
        return solve(prices, 0, 1);
    }
    int solve(vector<int>& prices, int i, int canBuy) {
        if(i >= n) {
            return 0;
        }
        if(dp[i][canBuy] != -1) {
            return dp[i][canBuy];
        }
        if(canBuy) {
            int skip = solve(prices, i+1, 1);
            int buy = -prices[i]+solve(prices, i+1, 0);
            return dp[i][canBuy] = max(skip, buy);
        }
        int sell = prices[i] + solve(prices, i+2, 1);
        int skip = solve(prices, i+1, 0);
        return dp[i][canBuy] = max(skip, sell);
    }
};
