class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int>st;

        for(int i=0; i<n; i++){
            if(s[i]=='[' or s[i]=='(' or s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                if((s[i]==')' && st.top()!='(')
                    or(s[i]=='}' && st.top()!='{')
                    or(s[i]==']' && st.top()!='[')){
                        return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
