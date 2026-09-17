class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int>mp; //nums->freq

        for(auto num : nums){
            mp[num]++;
        }

        for(auto it : mp){
            if(it.second>1) return true;
        }
        return false;
    }
};