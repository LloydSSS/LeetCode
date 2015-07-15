// http://www.lintcode.com/en/problem/scramble-string/
// 递归调用:太多重复子问题
// Time o(n3)
// 动态规划用数组来保存子问题，设dp[k][i][j]表示s2从j开始长度为k的子串是否可以由s1从i开始长度为k的子串转换而成，那么动态规划方程如下

//   初始条件：dp[1][i][j] = (s1[i] == s2[j] ? true : false)
//   dp[k][i][j] = ( dp[divlen][i][j] && dp[k-divlen][i+divlen][j+divlen] )  ||  ( dp[divlen][i][j+k-divlen] && dp[k-divlen][i+divlen][j] ) (divlen = 1,2,3...k-1, 它表示子串分割点到子串起始端的距离) ，只要一个子问题返回真，就可以停止计算

#include "lc.h"

class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;
        if (s1 == s2) return true;

        for (int i = 1; i < s1.size(); ++i) {
            string s11 = s1.substr(0,i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0,i);
            string s22 = s2.substr(i);
            string ss21 = s2.substr(0, s2.size()-i);
            string ss22 = s2.substr(s2.size()-i);
            if ((isScramble(s11, s21) && isScramble(s12, s22))
                ||(isScramble(s11, ss22) && isScramble(s12, ss21)))
                return true;
        }
        return false;
    }
};

class Solution2 {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string &s1, string &s2) {
        //动态规划解法
        if(s1.size() != s2.size())return false;
        const int len = s1.size();
        //dp[k][i][j]表示s2从j开始长度为k的子串是否可以由s1从i开始长度为k的子串转换而成
        vector<vector<vector<bool> > > dp(len+1, vector<vector<bool> >(len, vector<bool>(len, false)));
        //初始化长度为1的子串的dp值
        for(int i = 0; i <= len-1; i++)
            for(int j = 0; j <= len-1; j++)
                dp[1][i][j] = s1[i] == s2[j] ? true : false;
        for(int k = 2; k <= len; k++)//子串的长度
            for(int i = 0; i <= len-k; i++)//s1的起始位置
                for(int j = 0; j <= len-k; j++)//s2的起始位置
                {
                    dp[k][i][j] = false;
                    //divlen表示两个子串分割点到子串起始端的距离
                    for(int divlen = 1; divlen < k && !dp[k][i][j]; divlen++)
                        dp[k][i][j] = (dp[divlen][i][j] && dp[k-divlen][i+divlen][j+divlen])
                            || (dp[divlen][i][j+k-divlen] && dp[k-divlen][i+divlen][j]);
                }
        return dp[len][0][0];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
