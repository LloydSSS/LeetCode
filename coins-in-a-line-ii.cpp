// http://www.lintcode.com/zh-cn/problem/coins-in-a-line-ii/
// For any index i, we can know the gap between the two players if the first player moves from it. Suppose the first player moves from i and it wins f[i](the gap). If the second player moves from it, we should consider f[i] as a loss of the first player.
// http://techinpad.blogspot.com/2015/05/lintcode-coins-in-line-ii.html

#include "lc.h"

class Solution {
public:
    /**
     * @param values: a vector of integers
     * @return: a boolean which equals to true if the first player will win
     */
    bool firstWillWin(vector<int> &values) {
        int n = values.size();
        if (n <= 2) return true;
        vector<int> dp(n);
        dp[n-1] = values[n-1];
        dp[n-2] = values[n-2] + values[n-1];
        for (int i = n-3; i >= 0; --i)
            dp[i] = max(values[i]-dp[i+1], values[i]+values[i+1]-dp[i+2]);
        return dp[0] > 0;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
