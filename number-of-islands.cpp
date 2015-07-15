// http://www.lintcode.com/en/problem/number-of-islands/
// https://leetcode.com/problems/number-of-islands/
// BFS，水

#include "lc.h"

class Solution {
public:
    /**
     * @param grid a boolean 2D matrix
     * @return an integer
     */
    int numIslands(vector<vector<bool>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1)
                    continue;
                ans++;
                queue<pair<int, int> > qu;
                qu.push(make_pair(i, j));
                grid[i][j] = 0;
                while (!qu.empty()) {
                    pair<int, int> pr = qu.front();
                    qu.pop();
                    int x = pr.first;
                    int y = pr.second;
                    if (x != 0 && grid[x-1][y] == 1) {
                        qu.push(make_pair(x-1, y));
                        grid[x-1][y] = 0;
                    }
                    if (y != 0 && grid[x][y-1] == 1) {
                        qu.push(make_pair(x, y-1));
                        grid[x][y-1] = 0;
                    }
                    if (x != m-1 && grid[x+1][y] == 1) {
                        qu.push(make_pair(x+1, y));
                        grid[x+1][y] = 0;
                    }
                    if (y != n-1 && grid[x][y+1] == 1) {
                        qu.push(make_pair(x, y+1));
                        grid[x][y+1] = 0;
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
