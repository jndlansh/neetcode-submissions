class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0, r=0;
        unordered_set<char>st;
        int len = 0;
        while(r<n){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            len = max(len, r-l+1);
            st.insert(s[r]);
            r++;
        }
        return len;
    }
};
