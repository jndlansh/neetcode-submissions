class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, int i, int target, vector<int>& temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(i >= nums.size() || target < 0){
            return;
        }

        //take
        temp.push_back(nums[i]);
        solve(nums, i+1, target-nums[i], temp);
        temp.pop_back();

        //notTake
        int j=i+1;
        while(j<nums.size() && nums[i]==nums[j]){
            j++;
        }
        solve(nums, j, target, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, temp);
        return ans;
    }
};
