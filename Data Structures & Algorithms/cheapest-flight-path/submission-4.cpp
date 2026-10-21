class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dist(n, 1e9);
        dist[src] = 0;

        for(int i=0; i<=k; i++) {
            vector<int>tempDist = dist;

            for(auto& flight : flights) {
                int s = flight[0];
                int d = flight[1];
                int p = flight[2];

                if(dist[s] == 1e9) {
                    continue;
                }

                if(p+dist[s] < tempDist[d]) {
                    tempDist[d] = p+dist[s];
                }
            }
            dist = tempDist;
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
