class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_set<int>st(nums.begin(), nums.end());

        for(auto x : nums) {
            if(st.count(x-1)) {
                continue;
            }
            int curr = x;
            int cnt = 1;
            while(st.count(curr+1)) {
                curr++;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
