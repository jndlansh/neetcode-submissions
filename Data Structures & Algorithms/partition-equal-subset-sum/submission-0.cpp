class Solution {
public:
    int n;
    vector<vector<int>>dp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        n = nums.size();
        for(auto& num : nums) {
            sum+=num;
        }
        if(sum%2 != 0) return false;
        int target = sum/2;
        dp.assign(n+1, vector<int>(target+1, -1));

        return solve(nums, target, 0);
    }
    bool solve(vector<int>& nums, int sum, int i) {
        if(sum == 0) return true;
        if(i >= n) return false;
        // if(sum < 0) return false;

        if(dp[i][sum]!=-1) {
            return dp[i][sum];
        }

        int take = false;
        if(sum >= nums[i]) {
            take = solve(nums, sum-nums[i], i+1);
        }
        int notTake = solve(nums, sum, i+1);

        return dp[i][sum] = take || notTake;
    }
};
