class Solution {
public:
    set<pair<int, int>>path;
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i){
        if(i == word.size()) {
            return true;
        }

        if(r<0 || r>=board.size() || c<0 || c>=board[0].size() || path.count({r, c}) || word[i]!=board[r][c]) {
            return false;
        }
        path.insert({r, c});

        bool res = dfs(board, word, r+1, c, i+1) ||
                   dfs(board, word, r-1, c, i+1) ||
                   dfs(board, word, r, c+1, i+1) ||
                   dfs(board, word, r, c-1, i+1);
        path.erase({r, c});
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int r=0; r<n; r++) {
            for(int c=0; c<m; c++) {
                if(dfs(board, word, r, c, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
