class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char>st;
        for(auto c : s){
            if(c=='(' or c=='[' or c=='{'){
                st.push(c);
            }
            else{
                if(st.empty()) return false;

                if((c == ')' && st.top() != '(') ||
                   (c == ']' && st.top() != '[') ||
                   (c == '}' && st.top() != '{')) {
                    return false;
                }

                st.pop();
            }
            
        }
        return st.empty();
    }
};
