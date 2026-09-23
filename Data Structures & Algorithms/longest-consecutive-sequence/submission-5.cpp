class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int ans = 0;

        for(auto num : nums) {
            if(st.count(num-1)){
                continue;
            }
            int cnt=1;
            int curr=num;

            while(st.count(curr+1)) {
                cnt++;
                curr++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
