class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    void solve(string s, vector<string>& temp, int start) {
        if(start >= s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=start; i<s.size(); i++){
            if(!isPalindrome(s, start, i)) continue;
            temp.push_back(s.substr(start, i-start+1));

            solve(s, temp, i+1);

            temp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve(s, temp, 0);
        return ans;
    }
};
