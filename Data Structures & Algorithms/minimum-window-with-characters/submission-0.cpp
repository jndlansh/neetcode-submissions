class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n<m) return "";

        vector<int>mp(128, 0);

        for(auto it : t){
            mp[it]++;
        }
        int start=0, minLen=INT_MAX, l=0, cnt=t.size();

        for(int r=0; r<n; r++){
            if(mp[s[r]] > 0) cnt--;

            mp[s[r]]--;

            while(cnt == 0){
                if(minLen > r-l+1){
                    minLen = r-l+1;
                    start = l;
                }

                mp[s[l]]++;

                if(mp[s[l]] > 0){
                    cnt++;
                }
                l++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
