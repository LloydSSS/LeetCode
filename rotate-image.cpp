// http://www.lintcode.com/en/problem/rotate-image/
// 中轴翻转，对角线翻转

#include "lc.h"

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int l = 0; l < n; l++)
            for (int i = 0, j = n-1; i < j; ++i, --j) {
                swap(matrix[l][i],  matrix[l][j]);
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n-i-1; ++j) {
                swap(matrix[i][j], matrix[n-j-1][n-i-1]);
            }
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
