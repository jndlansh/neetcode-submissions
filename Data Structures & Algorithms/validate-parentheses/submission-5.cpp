class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto c: s){
            if(c=='[' or c=='(' or c=='{'){
                st.push(c);
            }else{
                if(st.empty()) return false;
                if((st.top()!='[' && c==']') 
                    or (st.top()!='{' && c=='}') 
                    or (st.top()!='(' && c==')')){
                        return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
