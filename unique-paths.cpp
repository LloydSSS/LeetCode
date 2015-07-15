// http://www.lintcode.com/en/problem/unique-paths/
// dp[i,j]表示到达(i,j)的路径数

#include "lc.h"

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        vector<int> dp(m, 1);
        for (int i = 1; i < n; ++i) {
        	for (int j = 1; j < m; ++j)
        		dp[j] = dp[j] + dp[j-1];
        }
        return dp[m-1];
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
	cout << sol.uniquePaths(2, 3) << endl;
	return 0;
}
