class Solution {
public:
    int rows, cols;
    set<pair<int, int>>path;
    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int i) {
        if(i == word.size()){
            return true;
        }
        if(r<0 || r>=rows || c<0|| c>=cols || board[r][c]!=word[i] || path.count({r, c})){
            return false;
        }
        path.insert({r, c});
        bool res = dfs(board, r+1, c, word, i+1) ||
                   dfs(board, r-1, c, word, i+1) ||
                   dfs(board, r, c+1, word, i+1) ||
                   dfs(board, r, c-1, word, i+1);
        path.erase({r, c});
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(dfs(board, r, c, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
