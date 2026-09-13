class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, int start, int target, vector<int>& temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        for(int i=start; i<nums.size(); i++){
            if(nums[i] > target) break;
            if(i>start && nums[i]==nums[i-1])continue;

            temp.push_back(nums[i]);
            solve(nums, i+1, target-nums[i], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, temp);
        return ans;
    }
};
