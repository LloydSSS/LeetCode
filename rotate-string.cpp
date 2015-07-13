// Rotate String
// http://www.lintcode.com/en/problem/rotate-string/
// a. 三次翻转
// b. 直接计算偏移

#include "lintcode.h"

class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        if (A.size() == 0) return A;
        offset %= A.size();
        // return A.substr(A.size()-offset) + A.substr(0, A.size()-offset);
        reverse(A.begin(), A.end());
        reverse(A.begin(), A.begin()+offset);
        reverse(A.begin()+offset, A.end());
        return A;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
