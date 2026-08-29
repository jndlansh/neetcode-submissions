class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m) return false;

        vector<int>hash(26, 0);
        for(auto it : s){
            hash[it-'a']++;
        }
        for(auto it : t){
            hash[it-'a']--;
        }
        for(int i=0; i<26; i++){
            if(hash[i]!=0) return false;
        }
        return true;
    }
};
