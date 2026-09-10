class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;

        for(auto str : strs){
            vector<int>hash(26, 0);
            string key = "";
            for(auto it : str){
                hash[it-'a']++;
            }
            for(int i=0; i<26; i++){
                key += to_string(hash[i])+'#';
            }

            mp[key].push_back(str);
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
