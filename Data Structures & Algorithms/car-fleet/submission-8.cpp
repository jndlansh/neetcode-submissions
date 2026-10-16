class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, double>>cars;
        // stack<double>st;

        for(int i=0; i<n; i++) {
            cars.push_back({pos[i], (double)(target-pos[i])/speed[i]});
        }

        sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double maxTime = 0;

        for(auto& it : cars) {
            double time = it.second;

            if(time > maxTime) {
                maxTime = time;
                fleets++;
            }
        }
        return fleets;
    }
};
