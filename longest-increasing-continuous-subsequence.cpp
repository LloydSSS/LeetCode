// http://www.lintcode.com/en/problem/longest-increasing-continuous-subsequence/
// 水dp
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
     * @param A an array of Integer
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequence(vector<int>& A) {
        if (A.size() <= 2) return A.size();
        int ans = 1;
        vector<int> dp(A.size()), dp2(A.size());
        dp[0] = 1;
        dp2[0] = 1;
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] >= A[i-1]) dp[i] = dp[i-1]+1;
            else dp[i] = 1;
            if (A[i] <= A[i-1]) dp2[i] = dp2[i-1]+1;
            else dp2[i] = 1;
            ans = max(ans, max(dp[i], dp2[i]));
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
