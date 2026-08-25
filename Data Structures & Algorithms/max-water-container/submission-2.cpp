class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans = 0;
        int n = heights.size();
        int l=0, r=n-1;
        while(l<r){
            ans = max(ans, (r-l)*min(heights[l], heights[r]));
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return ans;
    }
};
