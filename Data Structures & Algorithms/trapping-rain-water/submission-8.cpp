class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if(n<3) return 0;

        vector<int>preMax(n);
        vector<int>sufMax(n);
        preMax[0] = heights[0];
        sufMax[n-1] = heights[n-1];

        for(int i=1; i<n; i++) {
            preMax[i] = max(preMax[i-1], heights[i]);
        }
        for(int i=n-2; i>=0; i--) {
            sufMax[i] = max(sufMax[i+1], heights[i]);
        }
        int total = 0;
        for(int i=0; i<n; i++) {
            total += min(preMax[i], sufMax[i]) - heights[i];
        }
        return total;
    }
};
