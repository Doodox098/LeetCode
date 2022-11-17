class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        short check[27] = {0};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if((1 << (board[i][j] - '0')) & check[i])
                    return false;
                if((1 << (board[i][j] - '0')) & check[9 + j])
                    return false;
                if((1 << (board[i][j] - '0')) & check[18 + 3 * (i / 3) + j / 3])
                    return false;
                check[i] += 1 << (board[i][j] - '0');
                check[9 + j] += 1 << (board[i][j] - '0');
                check[18 + 3 * (i / 3) + j / 3] += 1 << (board[i][j] - '0');
            }
        }
        return true;
    }
};
