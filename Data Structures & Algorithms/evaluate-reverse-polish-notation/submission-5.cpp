class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;

        for(int i=0; i<n; i++) {
            if(!st.empty() && (tokens[i]=="+" or tokens[i]=="-" or tokens[i]=="*" or tokens[i]=="/")) {
                int first = st.top(); st.pop();
                int second = st.top(); st.pop();

                if(tokens[i] == "+") {
                    st.push(second+first);
                } else if(tokens[i] == "-") {
                    st.push(second-first);
                } else if(tokens[i] == "*") {
                    st.push(second*first);
                } else {
                    st.push(second/first);
                }
            } else {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
