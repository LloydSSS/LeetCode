// http://www.lintcode.com/en/problem/the-smallest-difference/
// a.排序，两个指针从头开始遍历，比较指针所指元素的difference，较小的指针后移

#include "lc.h"

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        int i = 0, j = 0;
        int ans = INT_MAX;
        while (i < A.size() && j < B.size()) {
            ans = min(ans, abs(A[i]-B[j]));
            if (A[i] > B[j]) {
                j++;
            } else if (A[i] < B[j]) {
                i++;
            } else {
                break;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
