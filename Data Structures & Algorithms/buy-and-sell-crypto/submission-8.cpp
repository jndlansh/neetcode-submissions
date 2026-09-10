class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int l = 0, r = 0;
        int ans = 0;

        while(r<n){
            if(prices[l]>prices[r]){
                l = r;
            }
            ans = max(ans, prices[r]-prices[l]);
            r++;
        }
        return ans;
    }
};
