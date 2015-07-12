// http://www.lintcode.com/en/problem/integer-to-roman/
// 将900，400等需要特殊处理的都放进字典里面

#include "lintcode.h"

class Solution {
public:
    /**
     * @param n The integer
     * @return Roman representation
     */
    string intToRoman(int n) {
        int base[]      = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string baseR[]  = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string s;
        int i = 0;
        while (n > 0) {
            if (n < base[i]) {
                i++;
            } else {
                s += baseR[i];
                n -= base[i];
            }
        }
        return s;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
