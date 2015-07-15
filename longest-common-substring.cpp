// http://www.lintcode.com/en/problem/longest-common-substring/
// dp[i,j] 表示A[0~i-1],B[0~j-1]之间的LCS的长度

#include "lc.h"

class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int alen = A.size();
        int blen = B.size();
        int ans = 0;
        vector<vector<int> > dp(alen, vector<int>(blen, 0));
        for (int i = 0; i < alen; ++i) {
            for (int j = 0; j < blen; ++j) {
                if (A[i] == B[j]) {
                    if (i != 0 && j != 0)
                    dp[i][j] = dp[i-1][j-1]+1;
                    else
                    dp[i][j] = 1;
                    ans = max(ans, dp[i][j]);
                }
            }
        }
      	return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	string s("ABCD");
	string t("ABCEssss");
	cout << sol.longestCommonSubstring(s, t) << endl;
	/* code */
	return 0;
}
