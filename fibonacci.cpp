// http://www.lintcode.com/en/problem/fibonacci/
// dp,基础题

#include "lintcode.h"

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i)
            dp[i%3] = dp[(i-1)%3] + dp[(i-2)%3];
        return dp[(n-1)%3];
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;

	cout << sol.fastPower(109, 10000007, 1000001) << endl;

	return 0;
}
