class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(auto it : nums){
            st.insert(it);
        }
        int ans = 0;
        for(auto x : st){
            if(st.count(x-1)){
                continue;
            }
            int curr=x;
            int cnt = 1;

            while(st.count(curr+1)){
                curr++;
                cnt++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
