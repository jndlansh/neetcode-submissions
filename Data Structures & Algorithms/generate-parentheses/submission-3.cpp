class Solution {
public:
    vector<string>ans;
    void solve(int open, int close, int n, string& s) {
        if(open == n && close == n) {
            ans.push_back(s);
            return;
        }

        if(open < n) {
            s.push_back('(');
            solve(open+1, close, n, s);
            s.pop_back();
        }
        if(close < open) {
            s.push_back(')');
            solve(open, close+1, n, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int close=0, open=0;
        string s = "";
        solve(open, close, n, s);
        return ans;
    }
};
