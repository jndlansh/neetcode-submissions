class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, vector<int>& temp, int target, int i) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(i >= nums.size() || nums[i] > target) {
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, temp, target-nums[i], i);
        temp.pop_back();
        solve(nums, temp, target, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        solve(nums, temp, target, 0);
        return ans;
    }
};
