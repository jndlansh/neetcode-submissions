class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(m<n) return false;

        vector<int>hash1(26, 0);
        for(auto it : s1){
            hash1[it-'a']++;
        }
        vector<int>hash2(26, 0);
        for(int i=0; i<n; i++){
            hash2[s2[i]-'a']++;
        }
        if(hash1 == hash2) return true;;
        for(int i=n; i<m; i++){
            hash2[s2[i]-'a']++;
            hash2[s2[i-n]-'a']--;
            if(hash1 == hash2){
                return true;
            }
        }
        return false;
    }
};
