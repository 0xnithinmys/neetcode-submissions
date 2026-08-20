class Solution {
   public:
    bool iscolvalid(vector<char> v) {
        unordered_map<char, int> u;

        for (int i = 0; i < v.size(); i++) {
            if(v[i] == '.')continue;
            u[v[i]]++;

            if (u[v[i]] > 1) return false;
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // row col traverse
        // add to map
        // freq >1 return false
        // 3*3
        // add to map
        // freq >1 return false

        // rowcol travere

        for (int i = 0; i < board.size(); i++) {
            if (!iscolvalid(board[i])) {
                return false;
            }
        }

        for (int i = 0; i < board[0].size(); i++) {
            vector<char> col;

            for (int j = 0; j < board.size(); j++) {
                col.push_back(board[j][i]);
            }

            if (!iscolvalid(col)) {
                return false;
            }
        }

        for (int i = 0; i < board.size(); i+=3) {
            for (int j = 0; j < board[0].size(); j+=3) {
                vector<char> o;

                for (int k = 0; k < 3; k++) {
                    for (int m = 0; m < 3; m++) {
                        o.push_back(board[i + k][j + m]);
                    }
                }

                if (!iscolvalid(o)) {
                    return false;
                }
            }
        }

        return true;
    }
};
