class Solution {
public:
    vector<vector<int>>ans;
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int>temp;
        vector<bool>used(n, false);
        solve(nums, temp, used);
        return ans;
    }
    void solve(vector<int>& nums, vector<int>& temp, vector<bool>& used) {
        // if(start >= n) return;
        if(temp.size() >= n) {
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<n; i++) {
            if(used[i]) continue;
            used[i] = true;
            temp.push_back(nums[i]);
            solve(nums, temp, used);
            used[i] = false;
            temp.pop_back();
        }
    }
};
