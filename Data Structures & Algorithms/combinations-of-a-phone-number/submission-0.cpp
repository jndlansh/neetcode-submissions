class Solution {
public:
    unordered_map<int, string>mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    vector<string>ans;
    void solve(string digits, string& temp, int start) {
        if(start >= digits.size()){
            ans.push_back(temp);
            return;
        }
        
        string digit = mp[digits[start]];

        for(auto it : digit){
            temp.push_back(it);
            solve(digits, temp, start+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        string temp ="";
        solve(digits, temp, 0);
        return ans;
    }
};
