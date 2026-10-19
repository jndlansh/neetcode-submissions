class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, vector<int>& temp, int start, int target) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        // if(start>=nums.size() || target < 0) {
        //     return;
        // }
        // temp.push_back(nums[start]);
        // solve(nums, temp, start+1, target-nums[start]);
        // temp.pop_back();

        // int j = start+1;
        // while(j<nums.size() && nums[start] == nums[j]) {
        //     j++;
        // }
        // solve(nums, temp, j, target);
        
        for(int i=start; i<nums.size(); i++) {
            if(nums[i] > target) break;
            if(i>start && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums, temp, i+1, target-nums[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int>temp;
        sort(nums.begin(), nums.end());

        solve(nums, temp, 0, target);
        return ans;
    }
};
