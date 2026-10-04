class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, vector<int>& temp, int target, int i) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(i >= nums.size() || target < 0) return;

        temp.push_back(nums[i]);
        solve(nums, temp, target-nums[i], i+1);
        temp.pop_back();
        int j=i+1;
        while(j<nums.size() && nums[j] == nums[i]) {
            j++;
        }
        solve(nums, temp, target, j);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        solve(nums, temp, target, 0);
        return ans;
    }
};
