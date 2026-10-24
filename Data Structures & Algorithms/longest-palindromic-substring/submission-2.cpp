class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int resLen=0, resInd=0;

        for(int i=0; i<n; i++) {
            int r=i, l=i;
            while(l>=0 && r<n && s[l]==s[r]) {
                if(r-l+1 > resLen) {
                    resLen = r-l+1;
                    resInd = l;
                }
                l--;
                r++;
            }
            r=i+1, l=i;
            while(l>=0 && r<n && s[l]==s[r]) {
                if(r-l+1 > resLen) {
                    resLen = r-l+1;
                    resInd = l;
                }
                l--;
                r++;
            }
        }   
        return s.substr(resInd, resLen);
    }
};
