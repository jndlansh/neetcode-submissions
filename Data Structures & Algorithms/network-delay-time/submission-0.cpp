class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>>adj(n+1);
        for(auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        } 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, k});

        vector<int>dist(n+1, 1e9);
        dist[k] = 0;

        while(!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto nei : adj[node]) {
                int adjNode = nei[0];
                int edgeWt = nei[1];
                if(dist[adjNode] > dis+edgeWt) {
                    dist[adjNode] = dis+edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }             
        }

        int ans=0;
        for(int i=1; i<=n; i++) {
            if(dist[i]==1e9) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
