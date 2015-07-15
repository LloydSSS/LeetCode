// http://www.lintcode.com/en/problem/count-primes/
// 每找到一个素数，则把他的倍数全部划掉

#include "lc.h"

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 1) return 0;
        vector<bool> isPrime(n+1, true);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans++;
                int cur = i+i;
                while (cur < n) {
                    isPrime[cur] = false;
                    cur += i;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
