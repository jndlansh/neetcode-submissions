class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool canPartition(vector<int>& nums) {
        n = nums.size();
        int sum = 0;
        for(auto num : nums) {
            sum += num;
        }
        if(sum%2 != 0) {
            return false;
        }
        int target = sum/2;
        dp.assign(n+1, vector<int>(target+1, -1));
        return solve(nums, target, 0);
    }
    int solve(vector<int>& nums, int target, int i) {
        if(i >= n) {
            return 0;
        }
        if(target == 0) {
            return 1;
        }
        if(dp[i][target] != -1) {
            return dp[i][target];
        }
        int take = false;;
        if(nums[i] <= target) {
            take = solve(nums, target-nums[i], i+1);
        }
        int notTake = solve(nums, target, i+1);

        return dp[i][target] = take || notTake;
    }
};