class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int>ans(n);
        stack<pair<int, int>>st;

        for(int i=0; i<n; i++){
            while(!st.empty() && t[i]>st.top().first){
                int ind = st.top().second;
                st.pop();
                ans[ind] = i-ind;
            }
            st.push({t[i], i});
        }
        return ans;
    }
};
