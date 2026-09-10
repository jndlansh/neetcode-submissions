class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char>st;
        int len = 0;
        int l = 0;

        for(int r=0; r<n; r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            len = max(len, r-l+1);
            st.insert(s[r]);
        }
        return len;
    }
};
