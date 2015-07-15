// A + B Problem
// http://www.lintcode.com/en/problem/a-b-problem/
// 位运算，一次性计算每一位的加和以及进位，当进位==0时停止计算

#include "lc.h"

class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
        // return a+b;
        int sum = 0, carry = 0;
        do {
            sum = a ^ b;
            carry = (a&b) << 1;
            a = sum;
            b = carry;
        } while (carry != 0);
        return sum;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
