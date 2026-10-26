class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        dp.assign(n, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, 0);
        return ans >= 1e9 ? -1 : ans;       
    }
    int solve(vector<int>& coins, int target, int i) {
        if(target == 0) {
            return 0;
        }
        if(i >= n) {
            return 1e9;
        }

        if(dp[i][target] != -1) {
            return dp[i][target];
        }

        int take = 1e9;
        if(coins[i] <= target) {
            take = 1+solve(coins, target-coins[i], i);
        }
        int notTake = solve(coins, target, i+1);

        return dp[i][target] = min(take, notTake);
    }
};
