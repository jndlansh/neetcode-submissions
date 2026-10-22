class Solution {
public:
    int n;
    int solve(vector<int>& nums, vector<int>& dp, int i, int n) {
        if(i >= n) return 0;

        if(dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = max(nums[i]+solve(nums, dp, i+2, n), solve(nums, dp, i+1, n));
    }
    int rob(vector<int>& nums) {
        vector<int>arr1(nums.begin(), nums.end()-1), arr2(nums.begin()+1, nums.end());
        n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(arr1.size(), -1);
        vector<int> dp2(arr2.size(), -1);
        return max(solve(arr1, dp1, 0, arr1.size()), solve(arr2, dp2, 0, arr2.size()));

    }
};
