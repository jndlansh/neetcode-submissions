class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();
        vector<pair<int, int>>cars(n);
        stack<double>st;
        for(int i=0; i<n; i++){
            cars[i] = {pos[i], speed[i]};
        }
        sort(cars.rbegin(), cars.rend());

        for(int i=0; i<n; i++){
            double speed = (double)(target - cars[i].first)/(double)(cars[i].second);
            if(st.empty() || st.top() < speed){
                st.push(speed);
            }
        }
        return st.size();
    }
};
