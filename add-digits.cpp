// https://leetcode.com/problems/add-digits/
// https://en.wikipedia.org/wiki/Digital_root

#include "lc.h"

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
