class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& arr, int i, int target, vector<int>& temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(i >= arr.size() || target < 0){
            return;
        } 
        temp.push_back(arr[i]);
        solve(arr, i+1, target-arr[i], temp);
        temp.pop_back();

        int j = i+1;
        while(j<arr.size() && arr[j] == arr[i]){
            j++;
        }
        solve(arr, j, target, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>temp;
        solve(candidates, 0, target, temp);
        return ans;
    }
};
