class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(int c='A'; c<='Z'; c++){
            int i=0, j=0, replaced=0;
            while(i<n){
                if(c==s[i]){
                    i++;
                }
                else if(replaced<k){
                    replaced++;
                    i++;
                }
                else if(s[j]==c){
                    j++;
                }
                else{
                    j++;
                    replaced--;
                }
                ans = max(ans, i-j);
            }
        }
        return ans;
    }
};
