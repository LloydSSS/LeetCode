// https://leetcode.com/problems/number-of-digit-one/
// 注意base可能溢出

#include "lc.h"

class Solution {
public:
    int countDigitOne(int n) {
        return digitCounts(1, n);
    }

    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        long long base = 1;
        int ans = 0;
        while (n >= base) {
            int low = n - (n/base)*base;
            int high = n/(base*10);
            int cur = (n/base)%10;
            if (cur < k)
                ans += high*base;
            else if (cur == k)
                ans += high*base + low + 1;
            else
                ans += (high+1) * base;
            base *= 10;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    cout << sol.countDigitOne(410065408) << endl;
    cout << sol.countDigitOne(1410065408) << endl;
    return 0;
}
