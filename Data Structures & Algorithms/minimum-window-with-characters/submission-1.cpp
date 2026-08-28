class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(m > n) return "";
        vector<int>hash(128, 0);

        for(auto it : t){
            hash[it]++;
        }

        int start=0, minLen=INT_MAX, l=0, cnt=m;
        for(int r=0; r<n; r++){
            if(hash[s[r]]>0) cnt--;
            hash[s[r]]--;

            while(cnt == 0){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    start = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt++;
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
