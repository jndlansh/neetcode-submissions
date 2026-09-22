class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        int n = grid.size();
        int m = grid[0].size();
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(grid[r][c] == 0){
                    q.push({r, c});
                }
            }
        }

        int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(int i=0; i<4; i++) {
                int nr = r+dir[i][0];
                int nc = c+dir[i][1];

                if(nr<0 || nr>=n || nc<0 || nc>=m || grid[nr][nc]!=INT_MAX){
                    continue;
                } 
                q.push({nr, nc});
                grid[nr][nc] = 1+grid[r][c];
            }
        }

    }
};
