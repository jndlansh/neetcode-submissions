class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int l=1, r=*max_element(piles.begin(), piles.end());

        while(l<=r){
            int mid = l+(r-l)/2;
            int time=0;
            for(auto it : piles) {
                time += it/mid;
                if(it % mid != 0) time++;
            }
            if(time <= h){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return l;
    }
};
 