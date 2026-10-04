class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, vector<int>& temp, int target, int start){
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(target<0 || start >= nums.size()) {
            return;
        }
        temp.push_back(nums[start]);
        solve(nums, temp, target-nums[start], start);
        temp.pop_back();
        solve(nums, temp, target, start+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        solve(nums, temp, target, 0);
        return ans;
    }
};
