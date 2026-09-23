class Solution { 
public: 
    vector<int> findOrder(int V, vector<vector<int>>& edges) { 
        
        vector<vector<int>> adj(V); 
        
        for(auto it : edges) {
            adj[it[1]].push_back(it[0]);
        }
         
        vector<int> indegree(V, 0); 
        
        for(int u = 0; u < V; u++) {
            for(int v : adj[u]) {
                indegree[v]++;
            }
        }
         
        queue<int> q; 
         
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
         
        vector<int> ans; 
         
        while(!q.empty()) {
            
            int node = q.front(); 
            q.pop(); 
             
            ans.push_back(node); 
             
            for(int nei : adj[node]) {
                indegree[nei]--;
                
                if(indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }
        
        if(ans.size() != V)
            return {};
        
        return ans;
    }
};