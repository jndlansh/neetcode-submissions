class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>mp;

        for(auto str : strs) {
            vector<int>hash(26, 0);
            for(auto it : str) {
                hash[it-'a']++;
            }
            string key = "";
            for(auto s : hash) {
                key += to_string(s)+'#';
            }
            mp[key].push_back(str);
        }
        for(auto it : mp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
