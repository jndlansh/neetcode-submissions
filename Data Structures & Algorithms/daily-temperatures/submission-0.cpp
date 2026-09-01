class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        stack<pair<int, int>>st;
        vector<int>ans(n, 0);
        int i=0;
        while(i<n){
            while(!st.empty() && t[i] > st.top().first){
                int index = st.top().second;
                ans[index] = i-index;
                st.pop();
            }
            st.push(make_pair(t[i], i));
            i++;
        }
        return ans;
    }
};
