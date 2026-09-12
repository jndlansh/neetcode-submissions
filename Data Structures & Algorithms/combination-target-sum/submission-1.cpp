class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, int i, int target, vector<int>& temp){
        
        if(i >= nums.size() || target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[i]);
        solve(nums, i, target-nums[i], temp);

        temp.pop_back();
        //notTake
        solve(nums, i+1, target, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        solve(nums, 0, target, temp);
        return ans;
    }
};
