// https://leetcode.com/problems/spiral-matrix-ii
// 模拟

#include "lc.h"

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        if (0 == n) return vector<vector<int> >();
        vector<vector<int> > matrix(n, vector<int>(n));
        int start_x = 0, start_y = 0, end_x = n, end_y = n;
        int i = 1;
        while (true) {
            for (int x = start_x; x < end_x; ++x)
                matrix[start_y][x] = i++;
            if (++start_y >= end_y) break;
            for (int y = start_y; y < end_y; ++y)
                matrix[y][end_x-1] = i++;
            if (start_x >= --end_x) break;
            for (int x = end_x-1; x >= start_x; --x)
                matrix[end_y-1][x] = i++;
            if (start_y >= --end_y) break;
            for (int y = end_y-1; y >= start_y; --y)
                matrix[y][start_x] = i++;
            if (++start_x >= end_x) break;
        }
        return matrix;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
