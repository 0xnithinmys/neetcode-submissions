class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            unordered_map<char,int> u;
            for(int j = 0; j < 9; j++) {
                char val = board[i][j];
                if(val != '.') {
                    if(u[val]) return false;
                    u[val] = 1;
                }
            }
        }

        for(int j = 0; j < 9; j++) {
            unordered_map<char,int> u;
            for(int i = 0; i < 9; i++) {
                char val = board[i][j];
                if(val != '.') {
                    if(u[val]) return false;
                    u[val] = 1;
                }
            }
        }

        for(int i = 0; i < 9; i += 3) {
            for(int j = 0; j < 9; j += 3) {
                unordered_map<char,int> u;
                for(int r = i; r < i + 3; r++) {
                    for(int c = j; c < j + 3; c++) {
                        char val = board[r][c];
                        if(val != '.') {
                            if(u[val]) return false;
                            u[val] = 1;
                        }
                    }
                }
            }
        }

        return true;
    }
};