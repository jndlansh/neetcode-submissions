class Solution {
public:
    int n, m;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<char>>& board, int r, int c) {
        if(r<0 || r>=n || c<0 || c>=m || board[r][c]!='O'){
            return;
        }
        board[r][c] = 'S';
        for(int i=0; i<4; i++) {
            dfs(board, r+dir[i][0], c+dir[i][1]);
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();

        for(int i=0; i<n; i++) {
            if(board[i][0] == 'O'){
                dfs(board, i, 0);
            }
            if(board[i][m-1] == 'O'){
                dfs(board, i, m-1);
            }
        }
        for(int i=0; i<m; i++) {
            if(board[0][i] == 'O') {
                dfs(board, 0, i);
            }
            if(board[n-1][i] == 'O') {
                dfs(board, n-1, i);
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'S'){
                    board[i][j] = 'O';
                }
                else if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
