// http://www.lintcode.com/en/problem/set-matrix-zeroes/
// 使用第一行第一列来标记，需要使用两个元素来标记第一行第一列是否需要被设为0

#include "lintcode.h"

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        bool row_zero = false;
        bool col_zero = false;
        for (int i = 0; i < matrix.size(); ++i)
            if (matrix[i][0] == 0) {
                col_zero = true;
                break;
            }
        for (int j = 0; j < matrix[0].size(); ++j)
            if (matrix[0][j] == 0) {
                row_zero = true;
                break;
            }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
            }
        }
        for (int i = 1; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[i].size(); ++j) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (col_zero)
            for (int i = 0; i < matrix.size(); ++i)
                matrix[i][0] = 0;
        if (row_zero)
            for (int j = 0; j < matrix[0].size(); ++j)
                matrix[0][j] = 0;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
