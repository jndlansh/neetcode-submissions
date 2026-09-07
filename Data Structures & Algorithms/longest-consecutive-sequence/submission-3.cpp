class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin(), nums.end());
        int ans = 0;

        for(auto it : st){
            if(st.count(it-1)) continue;
            int cnt = 1;
            int curr = it;

            while(st.count(curr+1)){
                cnt++;
                curr++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
