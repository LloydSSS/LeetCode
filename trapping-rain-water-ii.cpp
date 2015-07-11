// http://www.lintcode.com/zh-cn/problem/trapping-rain-water/
// O(n), O(n)   a.使用两个数组纪录每个位置左右的最高点，然后进行计算
// O(n), O(1)   b.两边往中间遍历，最高点不变，使用一个变量纪录第二高点，计算较低位置可以trap的雨量secHeight-heights[lower];
// O(n), O(1)   c.两遍遍历，从左向右，纪录最高的index，并纪录最高index到目前为止的block大小，如果遇到比最高index高的，则计算到目前为止trap的雨量；这样最高点往右的位置无法计算，需要从右向左遍历
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    struct Cell{
        int i;
        int j;
        int h;

        Cell(int i_ = 0, int j_ = 0, int h_  = 0) :
            i(i_), j(j_), h(h_) {}

        bool operator<(const Cell &c) const {
            return h > c.h;
        }
    };

    /**
     * @param heights: a matrix of integers
     * @return: an integer
     */
    int trapRainWater(vector<vector<int> > &heights) {
        m = heights.size();
        n = heights[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            heap.emplace(Cell(i, 0, heights[i][0]));
            heap.emplace(Cell(i, n-1, heights[i][n-1]));
        }
        for (int j = 0; j < n; ++j) {
            heap.emplace(Cell(0, j, heights[0][j]));
            heap.emplace(Cell(m-1, j, heights[m-1][j]));
        }

        int ans = 0;

        // BFS with min heap
        while (!heap.empty()) {
            Cell c = heap.top();
            heap.pop();
            visited[c.i][c.j] = true;

            ans += bfs(heights, c.i+1, c.j, c.h); // Up
            ans += bfs(heights, c.i-1, c.j, c.h); // Down
            ans += bfs(heights, c.i, c.j+1, c.h); // Right
            ans += bfs(heights, c.i, c.j-1, c.h); // Left
        }

        return ans;
    }

    int bfs(vector<vector<int> > &heights, int i, int j, int h) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j])
            return 0;
        visited[i][j] = true;
        heap.emplace(Cell{i, j, max(h, heights[i][j])});
        return max(0, h - heights[i][j]);
    }

    int m;
    int n;
    vector<vector<bool> > visited;
    priority_queue<Cell> heap;
};


int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
