// http://www.lintcode.com/en/problem/reverse-integer
// https://leetcode.com/problems/reverse-integer/
// 将结果设为long long 防止溢出

#include "lc.h"

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
        long long ans = 0;
        int flag = 1;
        if (n < 0) {
            flag = -1;
            n = flag*n;
        }
        while (n) {
            ans = ans*10 + n;
            n /= 10;
        }
        ans *= flag;
        if (ans > INT_MAX)
            ans = 0;
        if (ans < INT_MIN)
            ans = 0;

        return static_cast<int>(ans);
    }
};

int main(int argc, char const *argv[]) {
	return 0;
}
