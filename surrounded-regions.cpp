// https://leetcode.com/problems/surrounded-regions/
// 从边界开始bfs,将与边界相邻的点标记成B，最后把O变为X，B变成O

#include "lc.h"

class Solution {
public:
    struct point{
        int x;
        int y;
        point(int x_, int y_) : x(x_), y(y_) {}
    };
    void bfs(vector<vector<char> > &board, int i, int j) {
        if (board[i][j] != 'O') return;
        int di[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        int rows = board.size(), cols = board[0].size();
        queue<point> q;
        q.push(point(i, j));
        board[i][j] = 'B';
        while (!q.empty()) {
            point p = q.front();
            q.pop();
            int x = p.x, y = p.y;
            for (int d = 0; d < 4; ++d) {
                int nx = x+di[d][0];
                int ny = y+di[d][1];
                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || board[nx][ny] != 'O') {
                    continue;
                }
                board[nx][ny] = 'B';
                q.push(point(nx, ny));
            }
        }
    }
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0) return;
        vector<vector<bool> > record(board.size(), vector<bool>(false, board[0].size()));
        int rows = board.size(), cols = board[0].size();
        for (int i = 0; i < rows; ++i) {
            bfs(board, i, 0);
            bfs(board, i, cols-1);
        }
        for (int j = 0; j < cols; ++j) {
            bfs(board, 0, j);
            bfs(board, rows-1, j);
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'B') board[i][j] = 'O';
            }
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
