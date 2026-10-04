class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& nums, vector<int>& temp, int target, int i) {
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        // if(i >= nums.size() || target < 0) return;

        for(int start=i; start<nums.size(); start++) {
            if(nums[start] > target) break;
            if(start > i && nums[start]==nums[start-1]) continue;

            temp.push_back(nums[start]);
            solve(nums, temp, target-nums[start], start+1);
            temp.pop_back();
        }

        // temp.push_back(nums[i]);
        // solve(nums, temp, target-nums[i], i+1);
        // temp.pop_back();
        // int j=i+1;
        // while(j<nums.size() && nums[j] == nums[i]) {
        //     j++;
        // }
        // solve(nums, temp, target, j);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        solve(nums, temp, target, 0);
        return ans;
    }
};
