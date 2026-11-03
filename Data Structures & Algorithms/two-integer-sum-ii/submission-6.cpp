class Solution {
public:
    vector<int> twoSum(vector<int>& s, int target) {
        int n = s.size();
        int l=0, r=n-1;

        while(l<r) {
            if(s[l]+s[r] == target) {
                return {l+1, r+1};
            } 
            else if(s[l]+s[r] > target) {
                r--;
            } else {
                l++;
            }
        }
        return {};
    }
};
