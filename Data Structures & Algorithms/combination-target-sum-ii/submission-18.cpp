class Solution {
public:
    vector<vector<int>>ans;
    int n;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        n = nums.size();
        vector<int>temp;
        sort(nums.begin(), nums.end());
        solve(nums, temp, target, 0);
        return ans;
    }
    void solve(vector<int>& nums, vector<int>& temp, int target, int start) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        if(start >= n || target < 0) {
            return;
        }

        for(int i=start; i<n; i++) {
            if(i>start && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums, temp, target-nums[i], i+1);
            temp.pop_back();
        }
    }
};
