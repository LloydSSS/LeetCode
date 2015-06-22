// Wildcard Matching
// http://www.lintcode.com/en/problem/wildcard-matching/
// a. star 纪录上一个*的位置，ss纪录匹配*的s的位置，当发生不匹配的时候依次尝试ss+1, ss+2...是否匹配成功
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (s == NULL && p == NULL) return true;
        const char *ss = NULL, *star = NULL;
        while (*s != '\0') {
            if (*s == *p || *p == '?') {
                s++, p++;
            } else if (*p == '*') {
                star = p;
                p++;
                ss = s;
            } else if (star != NULL) {
                s = ++ss;
                p = star+1;
            } else
                return false;
        }
        while (*p == '*') p++;
        return (*p == '\0');
    }
};

int main(int argc, char const *argv[]) {

	Solution sol;

	return 0;
}
