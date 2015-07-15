// https://leetcode.com/problems/palindrome-number/
// 每次取最高位和最低位进行比较

#include "lc.h"

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int base = 1;
        while (x/base >= 10)
            base *= 10;
        while (x != 0) {
            int d = x%10;
            int b = x/base;
            if (b != d)
                return false;
            x -= b * base;
            x /= 10;
            base /= 100;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
