// http://www.lintcode.com/en/problem/first-missing-positive/
// https://leetcode.com/problems/first-missing-positive/
// 桶排序

#include "lc.h"

class Solution {
public:
    /**
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        int len = A.size();

        for (int i = 0; i < len; ++i) {
            while (A[i] > 0 && A[i] <= len && A[A[i]-1] != A[i]) {
                swap(A[A[i]-1], A[i]);
            }
        }
        for (int i = 0; i < len; ++i) {
            if (A[i] != i+1)
                return i+1;
        }
        return len+1;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
