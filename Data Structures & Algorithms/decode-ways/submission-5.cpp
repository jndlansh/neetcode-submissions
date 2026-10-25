class Solution {
public:
    int n;
    vector<int>dp;
    int numDecodings(string s) {
       n = s.size();
       dp.assign(n, -1);
       return solve(s, 0); 
    }
    int solve(string s, int i) {
        if(i == n) {
            return 1;
        }
        if(i > n) {
            return 0;
        }
        if(s[i] == '0') {
            return 0;
        }
        if(dp[i] != -1) {
            return dp[i];
        }

        int ways = solve(s, i+1);

        if(i+1<n) {
            int num = (s[i]-'0')*10 + (s[i+1]-'0');
            if(num>=10 && num<=26) {
                ways += solve(s, i+2);
            }
        }
        return dp[i] = ways;
    }

};
