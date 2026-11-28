class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<bool>used(nums.size(), false);
        solve(nums, used, temp);
        return ans;
    }
    void solve(vector<int>& nums, vector<bool>& used, vector<int>& temp) {
        if(temp.size() >= nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(used[i]) continue;
            used[i] = true;
            temp.push_back(nums[i]);

            solve(nums, used, temp);

            used[i] = false;
            temp.pop_back();
        }
    }
};
