class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int r=0;
        while(r<n){
            int l=r;
            while(l<n-1 && prices[l+1]>prices[r]){
                l++;
                profit = max(profit, prices[l]-prices[r]);
            }
            r=l+1;
        }
        return profit;
    }
};
