class Solution {
public:
    set<pair<int, int>>path;
    int row, col;
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i){
        if(i == word.size()){
            return true;
        }
        if(r>=row || r<0 || c>=col || c<0 || path.count({r, c}) || board[r][c] != word[i]){
            return false;
        }
        path.insert({r, c});
        bool res = dfs(board, word, r+1, c, i+1)
                   || dfs(board, word, r-1, c, i+1)
                   || dfs(board, word, r, c+1, i+1)
                   || dfs(board, word, r, c-1, i+1);

        path.erase({r, c});
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        for(int r=0; r<row; r++){
            for(int c=0; c<col; c++){
                if(dfs(board, word, r, c, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
