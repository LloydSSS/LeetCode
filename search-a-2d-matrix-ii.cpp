// http://www.lintcode.com/en/problem/search-a-2d-matrix-ii/
// 从左上角开始查找，每次走一步

#include "lc.h"

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) return 0;
        int x = matrix[0].size()-1, y = 0, ans = 0;
        while (x >= 0 && y < matrix.size()) {
            if (matrix[y][x] == target) {
                ans++;
                y++, x--;
            } else if (matrix[y][x] > target) {
                x--;
            } else {
                y++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
