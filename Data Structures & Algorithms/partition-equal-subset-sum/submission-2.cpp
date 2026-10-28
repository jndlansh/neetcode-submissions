class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        n = nums.size();
        for(auto num : nums) {
            sum += num;
        }
        if(sum%2!=0) {
            return false;
        }
        int target = sum/2;
        dp.assign(n+1, vector<int>(target+1, -1));
        return solve(nums, target, 0);
    }
    int solve(vector<int>& nums, int target, int i)  {
        if(target == 0) return true;
        if(i >= n) return false;

        if(dp[i][target] != -1) {
            return dp[i][target];
        }

        int take = false;
        if(target >= nums[i]) {
            take = solve(nums, target-nums[i], i+1);
        }
        int notTake = solve(nums, target, i+1);
        return dp[i][target] = take || notTake;
    }
};
