// https://leetcode.com/problems/number-of-1-bits/
// lintcode好像也有这道题

#include "lc.h"

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n = (n & (n-1));
            count++;
        }
        return count;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
