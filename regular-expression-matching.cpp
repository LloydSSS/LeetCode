// http://www.lintcode.com/en/problem/regular-expression-matching
// 暴力搜索：如果p的下一个字符不是*,则必须朴素匹配；如果p的下一个字符是*，则使用*匹配0~'\0'个字符
#include "lintcode.h"

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

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
