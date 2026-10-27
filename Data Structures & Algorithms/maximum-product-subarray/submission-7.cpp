class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxDP(n, -1), minDP(n, -1);
        maxDP[0] = nums[0], minDP[0] = nums[0];
        int ans = nums[0];

        for(int i=1; i<n; i++) {
            int x = nums[i];
            maxDP[i] = max({x, minDP[i-1]*x, maxDP[i-1]*x});
            minDP[i] = min({x, minDP[i-1]*x, maxDP[i-1]*x});
            ans = max(ans, maxDP[i]);
        }
        return ans;
    }
};
