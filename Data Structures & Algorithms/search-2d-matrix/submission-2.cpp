class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        int l=0, r=n*m-1;

        while(l<=r){
            int mid = l+(r-l)/2;

            if(mat[mid/m][mid%m] == target){
                return true;
            }else if(mat[mid/m][mid%m] > target){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return false;
    }
};
