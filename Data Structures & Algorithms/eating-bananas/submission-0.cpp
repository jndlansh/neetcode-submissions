class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low<=high){
            int mid = low + (high-low)/2;

            long long time = 0;
            for(auto p : piles){
                time += (p+mid-1)/mid;
            }

            if(time<=h){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};
