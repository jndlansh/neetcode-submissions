class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            unordered_set<char>seen;
            for(int j=0; j<9; j++){
                if(seen.count(board[i][j])) return false;
                if(board[i][j] == '.') continue;
                seen.insert(board[i][j]);
            }
        }
        for(int i=0; i<9; i++){
            unordered_set<char>seen;
            for(int j=0; j<9; j++){
                if(seen.count(board[j][i])) return false;
                if(board[j][i] == '.') continue;
                seen.insert(board[j][i]);
            }
        }
        for(int sq=0; sq<9; sq++){
            unordered_set<char>seen;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    int row = (sq/3)*3+i;
                    int col = (sq%3)*3+j;
                    if(seen.count(board[row][col])) return false;
                    if(board[row][col] == '.') continue;
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
