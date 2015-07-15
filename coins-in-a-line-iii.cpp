// http://www.lintcode.com/zh-cn/problem/coins-in-a-line-iii/
// dp[i][j] means the max profit the first player can get from j to i
// http://techinpad.blogspot.com/2015/05/lintcode-coins-in-line-iii.html

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
        vector<vector<int> > dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            dp[i][i] = values[i];
        for (int i = 1; i < n; ++i) {
            for (int j = i-1; j >= 0; --j) {
                dp[i][j] = max(values[i]-dp[i-1][j], values[j]-dp[i][j+1]);
            }
        }
        return dp[n-1][0] > 0;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v;
    cout << sol.firstWillWin(v) << endl;
	return 0;
}
