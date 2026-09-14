class Solution {
public:
    vector<string>ans;
    void solve(int openN, int closeN, int n, string &s){
        if(openN == n && closeN == n){
            ans.push_back(s);
            return;
        }

        if(openN < n){
            s.push_back('(');
            solve(openN+1, closeN, n, s);
            s.pop_back();
        }

        if(closeN < openN){
            s.push_back(')');
            solve(openN, closeN+1, n, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s="";
        solve(0, 0, n, s);
        return ans;
        
    }
};
