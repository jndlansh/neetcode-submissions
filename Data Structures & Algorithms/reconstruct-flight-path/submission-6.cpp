class Solution {
public:
    unordered_map<string, vector<string>>adj;
    vector<string>ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& it : tickets) {
            adj[it[0]].push_back(it[1]);
        }
        for(auto& [src, dest] : adj) {
            sort(dest.rbegin(), dest.rend());
        }
        dfs("JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }
    void dfs(string node) {
        while(!adj[node].empty()) {
            string nei = adj[node].back();
            adj[node].pop_back();
            dfs(nei);
        }
        ans.push_back(node);
    }
};
