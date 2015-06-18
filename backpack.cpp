#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @return: The maximum size
     */
    int backPack(int m, vector<int> A) {
        return backPack1D(m, A);
        if (m == 0) return 0;
        int n = A.size();
        // vector<vector<int> > dp(n, vector<int>(m+1)); // dp[i,j] 用m的容量装前i件物品的最大价值
        vector<vector<int> > dp(2, vector<int>(m+1));
        bool cur = 0;
        for (int i = 0; i < n; ++i) {
            cur = !cur;
            for (int j = 0; j <= m; ++j) {
                if (j >= A[i])
                    dp[cur][j] = max(dp[!cur][j], dp[!cur][j-A[i]] + A[i]);
                else
                    dp[cur][j] = dp[!cur][j];
            }
        }
        return dp[cur][m];
    }

    int backPack1D(int m, vector<int> A) {
        if (m == 0) return 0;
        int n = A.size();

        vector<int> dp(m+1);
        for (int i = 0; i < n; ++i) {
            for (int j = m; j >= A[i]; --j) {
                dp[j] = max(dp[j], dp[j-A[i]] + A[i]);
            }
        }
        return dp[m];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
