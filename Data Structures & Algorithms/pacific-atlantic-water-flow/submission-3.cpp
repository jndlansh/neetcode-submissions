class Solution {
public:
    int n, m;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& nums) {
        n = nums.size();
        m = nums[0].size();
        vector<vector<bool>>atl(n, vector<bool>(m, false)), pac(n, vector<bool>(m, false));

        for(int i=0; i<m; i++) {
            solve(nums, pac, 0, i);
            solve(nums, atl, n-1, i);
        }

        for(int i=0; i<n; i++) {
            solve(nums, pac, i, 0);
            solve(nums, atl, i, m-1);
        }
        vector<vector<int>>ans;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
    void solve(vector<vector<int>>& nums,vector<vector<bool>>& ocean, int r, int c) {
        ocean[r][c] = true;
        for(int i=0; i<4; i++) {
            int nr = r+dir[i][0];
            int nc = c+dir[i][1];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !ocean[nr][nc] && nums[nr][nc]>=nums[r][c]) {
                solve(nums, ocean, nr, nc);
            }
        }
    }
};
