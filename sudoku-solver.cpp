// https://leetcode.com/problems/sudoku-solver
// dfs valid[i][j][k]分别表示k在行，列，块是否可用

#include "lc.h"

class Solution {
public:
    bool valid[3][9][9];
    bool dfs(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') {
                    for (int k = 0; k < 9; ++k) {
                        if (valid[0][i][k] && valid[1][j][k] && valid[2][i/3*3+j/3][k]) {
                            valid[0][i][k] = false;
                            valid[1][j][k] = false;
                            valid[2][i/3*3+j/3][k] = false;
                            board[i][j] = '1' + k;
                            if (dfs(board)) return true;
                            board[i][j] = '.';
                            valid[0][i][k] = true;
                            valid[1][j][k] = true;
                            valid[2][i/3*3+j/3][k] = true;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char> > &board) {
        memset(valid, 1, sizeof(valid));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c != '.') {
                    valid[0][i][c-'1'] = false;
                    valid[1][j][c-'1'] = false;
                    valid[2][i/3*3+j/3][c-'1'] = false;
                }
            }
        }
        dfs(board);
    }
};

class Solution2 {
public:
    bool isValid(vector<vector<char> > &board, int a, int b) {
        for (int i = 0; i < 9; ++i) {
            if (i != a && board[i][b] == board[a][b])
                return false;
        }
        for (int j = 0; j < 9; ++j) {
            if (j != b && board[a][j] == board[a][b])
                return false;
        }
        int x = a / 3 * 3, y = b / 3 * 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (x + i != a && y + j != b && board[x + i][y + j] == board[a][b])
                    return false;
            }
        }
        return true;
    }
    bool dfs(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; ++k) {
                        board[i][j] = '1'+ k;
                        if (isValid(board, i, j) && dfs(board)) return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char> > &board) {
        dfs(board);
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
