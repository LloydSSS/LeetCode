// http://www.lintcode.com/zh-cn/problem/valid-sudoku/
// 检查column，row，block

#include "lintcode.h"

class Solution {
public:
    /**
      * @param board: the board
      * @return: wether the Sudoku is valid
      */
    bool isValidSudoku(const vector<string>& board) {
        bool flag[10];
        // column
        for (int i = 0; i < 9; ++i) {
            memset(flag, 0, sizeof(flag));
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.' )
                    continue;
                int val = board[i][j] - '0';
                if (flag[val])
                    return false;
                flag[val] = true;
            }
        }
        // row
        for (int i = 0; i < 9; ++i) {
            memset(flag, 0, sizeof(flag));
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] == '.' )
                    continue;
                int val = board[j][i] - '0';
                if (flag[val])
                    return false;
                flag[val] = true;
            }
        }
        //block
        int point[9][2] = {{0, 0}, {3, 0}, {6, 0}, {0, 3}, {3, 3}, {6, 3}, {0, 6}, {3, 6}, {6, 6}};
        int di[9][2] = {{0, 0}, {1, 0}, {1, 0}, {0, 1}, {-1, 0}, {-1, 0}, {0, 1}, {1, 0}, {1, 0}};
        for (int i = 0; i < 9; ++i) {
            memset(flag, 0, sizeof(flag));
            int x = point[i][0];
            int y = point[i][1];
            for (int j = 0; j < 9; ++j) {
                x += di[j][0];
                y += di[j][1];
                if (board[x][y] == '.' )
                    continue;
                int val = board[x][y] - '0';
                if (flag[val])
                    return false;
                flag[val] = true;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<string> v = {".87654321","2........","3........","4........","5........","6........","7........","8........","9........"};
    cout << sol.isValidSudoku(v) << endl;
	return 0;
}
