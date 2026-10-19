class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, vector<int>& temp, int i, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(i >= nums.size() || target<0) {
            return;
        }
        temp.push_back(nums[i]);
        solve(nums, temp, i, target-nums[i]);
        temp.pop_back();
        solve(nums, temp, i+1, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        solve(nums, temp, 0, target);
        return ans;
    }
};
