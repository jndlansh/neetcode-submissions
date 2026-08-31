class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin(), nums.end());
        int ans = 0;

        for(int x : st){
            if(st.count(x-1)) continue;

            int curr = x;
            int cnt = 1;

            while(st.count(curr+1)){
                cnt++;
                curr++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
