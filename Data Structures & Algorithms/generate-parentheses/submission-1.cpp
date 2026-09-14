class Solution {
public:
    vector<string>ans;
    void solve(int open, int close, int n, string& s) {
        if(open == n && close == n) {
            ans.push_back(s);
            return;
        }
        if(open < n){
            s.push_back('(');
            solve(open+1, close, n, s);
            s.pop_back();
        }
        if(close < open){
            s.push_back(')');
            solve(open, close+1, n, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        solve(0, 0, n, s);
        return ans;
    }
};
