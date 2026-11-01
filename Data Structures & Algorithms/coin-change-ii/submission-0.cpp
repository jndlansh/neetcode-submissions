class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        dp.assign(n+1, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, 0);
        return ans == -1 ? 0 : ans;
    }
    int solve(vector<int>& coins, int target, int i) {
        if(target == 0) {
            return 1;
        }
        if(i >= n) {
            return 0;
        }
        if(dp[i][target] != -1) {
            return dp[i][target];
        }
        int take = 0;
        if(coins[i] <= target) {
            take = solve(coins, target-coins[i], i);
        }
        int skip = solve(coins, target, i+1);
        return dp[i][target] = take+skip;
    }
};
