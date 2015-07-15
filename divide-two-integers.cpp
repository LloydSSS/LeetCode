// http://www.lintcode.com/en/problem/divide-two-integers/
// https://leetcode.com/problems/divide-two-integers/
// 用加法模拟除法，可以使用倍增的手段加速
#include "lc.h"

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        long long a = dividend;
        long long b = divisor;
        long long sum = 0;
        long long ans = 0, cnt = 0;
        bool flag = true;
        if ((a > 0 && b > 0) || (a < 0 && b < 0))
            flag = false;
        a = abs(a);
        b = abs(b);
        while (a >= b) {
            cnt = 1;
            sum = b;
            while (sum + sum <= a) {
                sum += sum;
                cnt += cnt;
            }
            a -= sum;
            ans += cnt;
        }
        if (flag)
            ans = 0 - ans;
        if (ans > INT_MAX || ans < INT_MIN)
            return INT_MAX;
        return static_cast<int>(ans);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
