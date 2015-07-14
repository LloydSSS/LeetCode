// Single Number II
// http://www.lintcode.com/en/problem/single-number-ii/
// a. 使用一个数组统计每位出现的次数，模3等于1的位则为single num
// b. 模拟三进制运算

#include "lintcode.h"

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : An integer
     */
    int singleNumberII(vector<int> &A) {
        int bitsum[32] = {0};
        for (int i = 0; i < A.size(); ++i) {
            int num = A[i];
            for (int j = 0; j < 32 && num != 0; ++j) {
                bitsum[j] += num & 1;
                num >>= 1;
            }
        }
        int m = 0;
        for (int j = 0; j < 32; ++j) {
            m += (bitsum[j]%3)<<j;
        }
        return m;
    }
    int singleNumberII2(vector<int> &A) {
        int ones = 0, twos = 0, threes = 0;
        for (int i = 0; i < A.size(); ++i) {
            twos |= ones & A[i];
            ones ^= A[i];
            threes = twos & ones;
            twos &= ~threes;
            ones &= ~threes;
        }
        return ones;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
