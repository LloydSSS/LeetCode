// https://leetcode.com/problems/spiral-matrix
// 模拟

#include "lc.h"

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        if (matrix.size() == 0)
            return result;
        int start_x = 0, start_y = 0, end_x = matrix[0].size(), end_y = matrix.size();
        while (true) {
            for (int x = start_x; x < end_x; ++x)
                result.push_back(matrix[start_y][x]);
            if (++start_y >= end_y) break;
            for (int y = start_y; y < end_y; ++y)
                result.push_back(matrix[y][end_x-1]);
            if (start_x >= --end_x) break;
            for (int x = end_x-1; x >= start_x; --x)
                result.push_back(matrix[end_y-1][x]);
            if (start_y >= --end_y) break;
            for (int y = end_y-1; y >= start_y; --y)
                result.push_back(matrix[y][start_x]);
            if (++start_x >= end_x) break;
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
