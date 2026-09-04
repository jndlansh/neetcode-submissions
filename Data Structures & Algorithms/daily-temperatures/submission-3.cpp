class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int>ans(n);
        stack<int>st;

        for(int i=0; i<n; i++){
            while(!st.empty() && t[i]>t[st.top()]){
                int ind = st.top();
                st.pop();
                ans[ind] = i-ind;
            }
            st.push(i);
        }
        return ans;
    }
};
