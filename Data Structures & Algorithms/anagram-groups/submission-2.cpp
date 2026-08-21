class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        for(auto &s:strs){
            vector<int>hash(26, 0);

            string key;

            for(auto c:s){
                hash[c-'a']++;
            }

            for(int i=0; i<26; i++){
                key += to_string(hash[i])+'#';
            }
            mp[key].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto &pair:mp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
