class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m) return false;

        vector<int>hash(26, 0);
        vector<int>hash1(26, 0);

        for(auto it : s1){
            hash[it-'a']++;
        }
        for(int i=0; i<n; i++){
            hash1[s2[i]-'a']++;
        }
        if(hash == hash1) return true;

        for(int i=n; i<m; i++){
            hash1[s2[i]-'a']++;

            hash1[s2[i-n]-'a']--;

            if(hash == hash1) return true;
        }
        return false;      
    }
};
