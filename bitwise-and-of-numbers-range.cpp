// https://leetcode.com/problems/bitwise-and-of-numbers-range/
// 当m!=n，那么最末位必定等0，因为[m,n]必定包含奇偶数，相与最末位等0。当m=n的时候，后面都是0，前面的就是这个范围内的数按位相与的相同部分。

#include "lc.h"

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if (m == 0) return 0;
        int factor = 0;
        while (m != n) {
            m >>= 1;
            n >>= 1;
            factor++;
        }
        return m << factor;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
