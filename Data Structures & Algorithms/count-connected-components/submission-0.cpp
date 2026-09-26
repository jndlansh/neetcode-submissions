class Solution {
public:
    int countComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<int>q;
        // q.push(0);
        vector<int>vis(V, false);
        // vis[0] = true;
        // vector<int>parent(V, -1);
        int cnt = 0;

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                q.push(i);
                vis[i] = true;
                cnt++;
            }
            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto nei : adj[node]) {
                    if(!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }
            // cnt++;
        }
        return cnt;        
    }
};
