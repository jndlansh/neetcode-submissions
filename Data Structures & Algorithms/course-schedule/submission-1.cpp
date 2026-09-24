class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(V);
        for(auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int>indegree(V, 0);
        for(int u=0; u<V; u++){
            for(int v : adj[u]){
                indegree[v]++;
            }
        }

        queue<int>q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int finish = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            finish++;

            for(auto nei : adj[node]) {
                indegree[nei]--;
                if(indegree[nei] == 0){
                    q.push(nei);
                }
            }
        }
        return finish == V;
    }
};
