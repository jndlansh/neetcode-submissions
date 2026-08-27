class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int r=0;
        int ans = 0;
        while(r<n){
            int l = r;
            while(l<n-1 && prices[l+1]>prices[r]){
                l++;
                ans = max(ans, prices[l]-prices[r]);
            }
            r = l + 1;
        }
        return ans;
    }
};
