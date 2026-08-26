class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        int profit = 0;
        int i = 0;
        while(i < n){
            int j = i;
            while(j<n-1 && nums[j+1]>nums[i]){
                j++;
                profit = max(profit, nums[j]-nums[i]);
            }
            i=j+1;
        }
        return profit;
    }
};
