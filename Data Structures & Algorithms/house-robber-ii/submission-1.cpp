class Solution {
public:
    int n;
    int rob(vector<int>& nums) {
       n = nums.size();
       if(n == 1) return nums[0];
       vector<int>arr1(nums.begin(), nums.end()-1), arr2(nums.begin()+1, nums.end());
       vector<int>dp1(arr1.size(), -1), dp2(arr2.size(), -1);

       return max(solve(arr1, dp1, 0), solve(arr2, dp2, 0)); 
    }
    int solve(vector<int>& nums, vector<int>& dp, int i) {
        if(i >= n-1) {
            return 0;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        return dp[i] = max(nums[i]+solve(nums, dp, i+2), solve(nums, dp, i+1));
    }
};
