// http://www.lintcode.com/en/problem/triangle/
// 最小路径和，dp基础题

#include "lc.h"

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        vector<int> dp(n, -1);
        dp[0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == i)
                    dp[j] = dp[j-1] + triangle[i][j];
                else if (j == 0)
                    dp[j] = dp[j] + triangle[i][j];
                else
                    dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; ++i)
            ans = min(ans, dp[i]);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<vector<int> > vv(2);
    vv[0] = {1, 0};
    vv[1] = {2, 3};
    cout << sol.minimumTotal(vv) << endl;
    return 0;
}
