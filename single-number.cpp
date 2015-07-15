// http://www.lintcode.com/en/problem/single-number/
// https://leetcode.com/problems/single-number/
// 相同数字异或为0

#include "lc.h"

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
    	if (A.size() == 0) return 0;
        int ans = A[0];
        for (int i = 1; i < A.size(); ++i)
        	ans ^= A[i];
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
