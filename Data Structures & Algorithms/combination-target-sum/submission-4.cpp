;class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, vector<int>& temp, int target, int start) {
        if(target < 0) return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i=start; i<nums.size(); i++){
            if(target - nums[i] < 0) break;

            temp.push_back(nums[i]);
            solve(nums, temp, target-nums[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        sort(nums.begin(), nums.end());
        solve(nums, temp, target, 0);
        return ans;
    }
};
