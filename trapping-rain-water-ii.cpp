// http://www.lintcode.com/zh-cn/problem/trapping-rain-water-ii/
// 使用一个堆维护坐标高度，从四周向中间蔓延，每次取最低点进行计算，寻找四周比它还低的点（只有这些点可以保存雨水，其他店都会流出去）

#include "lintcode.h"

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
