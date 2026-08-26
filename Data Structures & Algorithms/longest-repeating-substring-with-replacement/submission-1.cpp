class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int ans = 0;
        for(char c = 'A'; c<='Z'; c++){
            int i=0, j=0, replaced=0;
            while(j<n){
                if(s[j] == c){
                    j++;
                }else if(k>replaced){
                    j++;
                    replaced++;
                }else if(s[i] == c){
                    i++;
                }else{
                    i++;
                    replaced--;
                }
                ans = max(ans, j-i);
            }
        }
        return ans;
    }
};
