#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
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
     * @param A: An integer array.
     * @param target: An integer.
     */
    int MinAdjustmentCost(vector<int> A, int target) {
        int n = A.size();
        if (n <= 1) return 0;
        vector<vector<int> > dp(n, vector<int>(101, INT_MAX));
        for (int i = 1; i <= 100; ++i)
            dp[0][i] = abs(i-A[0]);
        for (int j = 1; j < n; ++j) {
            for (int i = 1; i <= 100; ++i) {
                int diff = abs(i-A[j]);
                int upper = min(i+target,100);
                int lower = max(i-target,1);
                for(int k = lower; k <= upper; ++k) {
                    dp[j][i] = min(dp[j][i], dp[j-1][k]+diff);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= 100; ++i) {
            ans = min(dp[n-1][i], ans);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
