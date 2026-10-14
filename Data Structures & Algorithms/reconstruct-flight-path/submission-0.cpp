class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> ans;
    void dfs(string node) {
        while(!adj[node].empty()) {
            string nei = adj[node].back();
            adj[node].pop_back();
            dfs(nei);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        for(auto& it : tickets) {
            adj[it[0]].push_back(it[1]);
        }

        for(auto& [airport, destination] : adj) {
            sort(rbegin(destination), rend(destination));
        }
        dfs("JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
