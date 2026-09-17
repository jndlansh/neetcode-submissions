class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, vector<int>& temp, int target, int start) {
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int i=start; i<nums.size(); i++){
            if(nums[i] > target) break;
            if(i>start && nums[i]==nums[i-1]) continue;

            temp.push_back(nums[i]);
            solve(nums, temp, target-nums[i], i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        solve(nums, temp, target, 0);
        return ans;
    }
};
