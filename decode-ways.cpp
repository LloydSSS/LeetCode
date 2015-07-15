// http://www.lintcode.com/en/problem/decode-ways/
// 从后向前decode
// 有条件的斐波那契数列

#include "lc.h"

class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;
        int n = s.size();
        vector<int> dp(n+1);
        dp[n] = 1;
        if (s[n-1] == '0') dp[n-1] = 0;
        else dp[n-1] = 1;
        for (int i = n-2; i >= 0; --i) {
            if (s[i] == '0') dp[i] = 0;
            else if (s[i] == '1' || (s[i] == '2' && s[i+1] >= '0' && s[i+1] <= '6')) {
                dp[i] = dp[i+1] + dp[i+2];
            } else {
                dp[i] = dp[i+1];
            }
        }
        return dp[0];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
