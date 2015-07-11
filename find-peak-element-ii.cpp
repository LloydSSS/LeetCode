// http://www.lintcode.com/en/problem/find-peak-element-ii/
// T(m, n) = T(m, n / 2) + O(m) = T(m / 2, n / 2) + O(m) + O(n / 2) = ... = O(2m) + O(2n) = O(max(m, n))
// 两个方向二分,统计中点及两侧的最大值，进行比较，判断峰值一定在哪里
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param A: An integer matrix
     * @return: The index of the peak
     */
    vector<int> findPeakII(vector<vector<int> > A) {
        int upper = 0, down = A.size()-1;
        int left = 0, right = A[0].size()-1;
        while (upper < down && left < right) {
            int height = down-upper+1;
            int width = right-left+1;
            int max_i = -1, max_j = -1;
            if (height > width) {   // Vertical split.
                int mid_j = (right+left)/2;
                int left_max = 0, central_max = 0, right_max = 0;
                for (int i = upper+1; i < down; ++i) {
                    if (A[i][mid_j] > central_max) {
                        max_i = i, max_j = mid_j;
                        central_max = A[i][mid_j];
                    }
                    left_max = max(left_max, A[i][mid_j-1]);
                    right_max = max(right_max, A[i][mid_j+1]);
                }
                if (left_max > right_max && left_max > central_max)
                    right = mid_j;
                else if (left_max < right_max && right_max > central_max)
                    left = mid_j;
                else
                    return {max_i, max_j};
            } else {    // Horizontal split.
                int mid_i = (upper+down)/2;
                int upper_max = 0, central_max = 0, down_max = 0;
                for (int j = left+1; j < right; ++j) {
                    if (A[mid_i][j] > central_max) {
                        max_i = mid_i, max_j = j;
                        central_max = A[mid_i][j];
                    }
                    upper_max = max(upper_max, A[mid_i-1][j]);
                    down_max = max(down_max, A[mid_i+1][j]);
                }
                if (upper_max > down_max && upper_max > central_max)
                    down = mid_i;
                else if (upper_max < down_max && down_max > central_max)
                    upper = mid_i;
                else
                    return {max_i, max_j};
            }
        }
        return {-1, -1};
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
