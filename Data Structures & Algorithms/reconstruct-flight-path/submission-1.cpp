class Solution {
public:
    vector<string> ans;
    unordered_map<string, vector<string>>adj;
    void dfs(string node) {
        while(!adj[node].empty()) {
            string nei = adj[node].back();
            adj[node].pop_back();
            dfs(nei);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& it : tickets) {
            adj[it[0]].push_back(it[1]);
        }

        for(auto& [airport, destinations] : adj) {
            sort(destinations.rbegin(), destinations.rend());
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
