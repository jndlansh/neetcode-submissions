class Solution {
public:
    int solve(int n, vector<int>& cost, vector<int>& dp) {
        if(n==0) return cost[n];
        if(n<0) return 0;

        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = cost[n]+min(solve(n-1, cost, dp), solve(n-2, cost, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1, -1);
        return min(solve(cost.size()-1, cost, dp), solve(cost.size()-2, cost, dp));
    }
};
