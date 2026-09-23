class Solution {
public:
    int n, m;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c) {
        ocean[r][c] = true;
        for(int i=0; i<4; i++) {
            int nr = r+dir[i][0];
            int nc = c+dir[i][1];

            if(nr>=0 && nr<n && nc>=0 && nc<m && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, ocean, nr, nc);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pac(n, vector<bool>(m, false));
        vector<vector<bool>>atl(n, vector<bool>(m, false));

        for(int i=0; i<m; i++) {
            dfs(heights, pac, 0, i);
            dfs(heights, atl, n-1, i);
        }

        for(int i=0; i<n; i++) {
            dfs(heights, pac, i, 0);
            dfs(heights, atl, i, m-1);
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
