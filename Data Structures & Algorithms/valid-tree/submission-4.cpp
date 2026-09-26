class Solution {
public:
    bool validTree(int V, vector<vector<int>>& edges) {
        if(edges.size() != V-1) {
            return false;
        }
        if(V==1 && edges.empty()) {
            return true;
        }
        vector<vector<int>>adj(V);
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool>vis(V, false);
        vector<int>parent(V, -1);
        int cnt=1;
        queue<int>q;

        q.push(0);
        vis[0] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto nei : adj[node]) {
                if(vis[nei]) {
                    if(nei != parent[node]){
                        return false;
                    }
                } 
                else {
                    vis[nei] = true;
                    parent[nei] = node;
                    q.push(nei);
                    cnt++;
                }
            }
        }
        return cnt == V;
    }
};
