class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+1);
        vector<int>indegree(n+1, 0);

        for(auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        queue<int>q; //push all lead nodes in the queue and decrease there indgreee and decrease neighbours indegree and if their indegree becomes 1, push them in queue

        for(int i=1; i<=n; i++) {
            if(indegree[i] == 1) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front(); q.pop();
            indegree[node]--;

            for(auto nei : adj[node]) {
                indegree[nei]--;
                if(indegree[nei]==1) {
                    q.push(nei);
                }
            }
        }
        for(int i=n-1; i>=0; i--) {
            if(indegree[edges[i][0]]==2 && indegree[edges[i][1]]==2) {
                return {edges[i][0], edges[i][1]};
            }
        }
        return {};
    }
};
