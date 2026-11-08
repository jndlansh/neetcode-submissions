class Solution {
public:
    vector<vector<int>>ans;
    int n;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>temp;
        solve(nums, temp, 0);
        return ans;
    }
    void solve(vector<int>& nums, vector<int>& temp, int start) {
        ans.push_back(temp);

        for(int i=start; i<n; i++) {
            if(i>start && nums[i] == nums[i-1]) {
                continue;
            }
            temp.push_back(nums[i]);
            solve(nums, temp, i+1);
            temp.pop_back();
        }
    }
};
