class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        if(n<3) return 0;

        int total = 0;
        int l = 0, r = n-1;
        int lmax = heights[l], rmax = heights[r];

        while(l<r) {
            if(lmax < rmax) {
                l++;
                lmax = max(lmax, heights[l]);
                total += lmax-heights[l];
            } else {
                r--;
                rmax = max(rmax, heights[r]);
                total += rmax-heights[r];
            }
        }
        return total;
    }
};
