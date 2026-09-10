class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        int ans = 0;
        for(auto x : st){
            if(st.count(x-1)){
                continue;
            }

            int cnt = 1;
            int curr = x;

            while(st.count(curr+1)){
                cnt++;
                curr++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
