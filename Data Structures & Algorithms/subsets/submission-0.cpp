class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, int i, vector<int>& subset){
        if(i >= nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        solve(nums, i+1, subset);
        subset.pop_back();
        solve(nums, i+1, subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subset;
        solve(nums, 0, subset);
        return ans;
    }
};
