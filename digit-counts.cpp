// Digit Counts
// http://www.lintcode.com/en/problem/digit-counts/
// a. 遍历0~n判断每个数字中出现k几次 O(nlogn)
// b. 判断每一位中k出现了几次，和高位数，低位数以及当前数字都有关系，分情况讨论 O(logn)
//     注意base应使用long long 防止溢出

#include "lc.h"

class Solution {
public:
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
    return 0;
}
