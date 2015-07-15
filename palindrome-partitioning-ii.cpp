// https://leetcode.com/problems/palindrome-partitioning-ii/
// Time O(n2)
// dp[i,j]表示i,j之间是否是回文
// cut[i]表示0~i之间的cut数

#include "lc.h"

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool> > dp(s.size(), vector<bool>(s.size()));
        vector<int> cut(s.size(), 0);
        vector<string> pa;

        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = true;
        }
        for (int k = 1; k < s.size(); ++k) {
            for (int i = 0; i + k < s.size(); ++i) {
                int j = i + k;
                if (j == i + 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                }
            }
        }
        for (int i = 1; i < s.size(); ++i) {
            if (dp[0][i]) {
                cut[i] = 0;
                continue;
            }
            int min_cut = INT_MAX;
            for (int j = 1; j <= i; ++j) {
                if (dp[j][i]) {
                    if (cut[j-1]+1 < min_cut)
                        min_cut = cut[j-1]+1;
                }
            }
            cut[i] = min_cut;
        }

        return cut[s.size()-1];
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
