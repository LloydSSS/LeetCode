// http://www.lintcode.com/en/problem/unique-binary-search-trees/
// https://leetcode.com/problems/unique-binary-search-trees/
// dp[i] 表示i个节点可以组成的bst的数量
// dp[i] = ∑(dp[j]*dp[i-j-1])

#include "lc.h"

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        if (n == 0 || n == 1) return 1;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
        	for (int j = 0; j < i; ++j) {
        		dp[i] += dp[j]*dp[i-j-1];
        	}
        }
        return dp[n];
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	cout << sol.numTrees(3) << endl;
	return 0;
}
