class Solution {
public:
    int n, m;
    set<pair<int, int>>path;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if(i == word.size()) {
            return true;
        }

        if(r<0 || r>=n || c<0 || c>=m || path.count({r, c}) || word[i]!=board[r][c]) {
            return false;
        }

        path.insert({r, c});

        bool res = dfs(board, word, r+1, c, i+1) || dfs(board, word, r-1, c, i+1) || dfs(board, word, r, c+1, i+1) || dfs(board, word, r, c-1, i+1);
        path.erase({r, c});
        return res;
    }
};
