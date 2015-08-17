// http://www.lintcode.com/en/problem/regular-expression-matching
// https://leetcode.com/problems/regular-expression-matching/
// 暴力搜索：如果p的下一个字符不是*,则必须朴素匹配；如果p的下一个字符是*，则使用*匹配0~'\0'个字符
#include "lc.h"

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (*p == '\0') return *s == '\0';
        if (*(p+1) != '*') {
            return ((*s == *p) || (*s != '\0' && *p == '.')) && isMatch(s+1, p+1);
        } else {
            while ((*s == *p) || (*s != '\0' && *p == '.')) {
                if (isMatch(s, p+2)) return true;
                s++;
            }
        }
        return isMatch(s, p+2);
    }
};

/*
This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are:

P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.
*/

class Solution_dp {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool> > dp(m + 1, vector<bool> (n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                else dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
        return dp[m][n];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    Solution_dp soldp;
    cout << sol.isMatch("a", "ab**") << endl;
    return 0;
}
