class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 

    void dfs(int r, int c, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        ocean[r][c] = true;
        for(auto [dr, dc] : dir) {
            int nr = r+dr, nc = c+dc;
            if(nr >= 0 && nr < heights.size() && nc>=0 && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, ocean, heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<bool>> pac (r, vector<bool>(c, false));
        vector<vector<bool>> atl (r, vector<bool>(c, false));

        for(int i=0; i<c; i++) {
            dfs(0, i, pac, heights);
            dfs(r-1, i, atl, heights);
        }
        for(int j=0; j<r; j++){
            dfs(j, 0, pac, heights);
            dfs(j, c-1, atl, heights);
        }

        vector<vector<int>>res;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
