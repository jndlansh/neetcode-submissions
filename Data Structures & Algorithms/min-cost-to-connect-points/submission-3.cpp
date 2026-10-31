class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, vector<pair<int, int>>>adj;
        for(int i=0; i<n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=i+1; j<n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1-x2) + abs(y1-y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 0});
        unordered_set<int>vis;
        int res = 0;

        while(vis.size() < n) {
            auto [cost, node] = pq.top(); pq.pop();
            if(vis.count(node)) continue;
            res += cost;
            vis.insert(node);

            for(auto nei : adj[node]) {
                int neiNode = nei.second;
                int neiCost = nei.first;
                if(!vis.count(neiNode)) {
                    pq.push({neiCost, neiNode});
                }
            }
        }
        return res;
    }
};
