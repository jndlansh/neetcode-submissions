class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<3) return 0;
        int total = 0;
        int l=0;
        int r=n-1;
        int leftMax=0, rightMax=0;

        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]>=leftMax){
                    leftMax = height[l];
                }else{
                    total += leftMax - height[l];
                }
                l++;
            }
            else{
                if(height[r]>=rightMax){
                    rightMax = height[r];
                }else{
                    total += rightMax - height[r];
                }
                r--;
            }
        }

        
        return total;
    }
};
