class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int>st;
        for(int i=0; i<s.size(); i++){
            if(!st.empty() && (s[i]=="+" || s[i]=="-" || s[i]=="*" || s[i]=="/")){
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();
                
                if(s[i]=="+"){
                    st.push(second + first);
                }else if(s[i]=="-"){
                    st.push(second - first);
                }else if(s[i]=="*"){
                    st.push(second * first);
                }else{
                    st.push(second / first);
                }
            }else{
                st.push(stoi(s[i]));
            }
        }
        return st.top();
    }
};
