class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n), suf(n), ans(n);
        pre[0] = 1, suf[n-1] = 1;

        for(int i=1; i<n; i++) {
            pre[i] = pre[i-1]*nums[i-1];
            suf[n-i-1] = suf[n-i]*nums[n-i];
        }
        for(int i=0; i<n; i++) {
            ans[i] = pre[i]*suf[i];
        }
        return ans;
    }
};
