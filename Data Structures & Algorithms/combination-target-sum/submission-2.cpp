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

            temp.push_back(nums[i]);

            solve(nums, i, target-nums[i], temp);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int>temp;
        solve(nums, 0, target, temp);
        return ans;
    }
};
