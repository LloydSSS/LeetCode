// http://www.lintcode.com/en/problem/post-office-problem/
// 状态：dp[i][j]：前i个村庄建j个邮局的最小花费
// 转移方程：dp[i][j] = min(dp[i][j], dp[k][j-1]+ dis[k+1][i]);
// dis[i][j]表示村庄i到村庄j之间建一个邮局的花费(花费为邮局到每个村庄的距离)
// 可以证明，当仅建立一个邮局时，最优解出现在中位数
// dis[i][j] = dis[i][j-1] + A[j] - A[(i+j)/2]

#include "lc.h"

class Solution {
public:
    /**
     * @param A an integer array
     * @param k an integer
     * @return an integer
     */
    int postOffice(vector<int>& A, int k) {
        int n = A.size();
        if (n <= 1 || n <= k) return 0;
        int ans = 0;
        vector<vector<int> > dp(n, vector<int>(k)),
                            dis(n, vector<int>(n));
        sort(A.begin(), A.end());
        for (int i = 0; i < n; ++i)
            for (int j = i+1; j < n; ++j)
                dis[i][j] = dis[i][j-1] + A[j] - A[(i+j)>>1];

        for (int i = 0; i < n; ++i)
            dp[i][0] = dis[0][i];

        for (int j = 1; j < k; ++j) {
            for (int i = j; i < n; ++i) {
                dp[i][j] = INT_MAX;
                for (int l = 0; l < i; ++l)
                    dp[i][j] = min(dp[i][j], dp[l][j-1]+dis[l+1][i]);
            }
        }
        return dp[n-1][k-1];
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> v = {112,122,360,311,85,225,405,53,405,43,342,13,588,424,299,37,104,289,404,414};
    cout << sol.postOffice(v, 3) << endl;
    return 0;
}
