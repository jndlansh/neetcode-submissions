class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int maxArea = 0;

        for(int i=0; i<=n; i++){
            while(!st.empty() && (i==n or heights[i]<heights[st.top()])){
                int ht = heights[st.top()];
                st.pop();
                int wd;
                if(st.empty()){
                    wd = i;
                }else{
                    wd = i-st.top()-1;
                }
                maxArea = max(maxArea, ht*wd);
            }
            st.push(i);
        }
        return maxArea;
    }
};
