// http://www.lintcode.com/en/problem/search-a-2d-matrix/
// https://leetcode.com/problems/search-a-2d-matrix/
// 直接二分

#include "lc.h"

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0, r = m*n;
        while (l < r) {
            int mid = (l+r) >> 1;
            int x = mid/n, y = mid%n;
            if (matrix[x][y] < target)
                l = mid+1;
            else if (matrix[x][y] > target)
                r = mid;
            else
                return true;
        }
        return false;
    }
};


int main(int argc, char const *argv[]) {

	Solution sol;
	return 0;
}
