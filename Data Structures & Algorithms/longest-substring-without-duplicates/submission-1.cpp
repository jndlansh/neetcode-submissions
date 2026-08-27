class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;
        int n = s.size();
        int r=0;
        int ans = 0, l = 0;
        while(r<n){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            ans = max(ans, r-l+1);
            st.insert(s[r]);
            r++;
        }
        return ans;
    }
};
