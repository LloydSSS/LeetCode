// String to Integer(atoi)
// http://www.lintcode.com/en/problem/string-to-integeratoi/
// https://leetcode.com/problems/string-to-integer-atoi/
// 注意边界情况，一遍AC有难度

#include "lc.h"

class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        int idx = 0;
        int len = str.size();
        long long num = 0;
        int flag = 1;
        // leading spaces
        while (idx < len && str[idx] == ' ')
            idx++;
        // -/+
        if (idx < len && str[idx] == '-') {
            flag = -1;
            idx++;
        } else if (idx < len && str[idx] == '+') {
            flag = 1;
            idx++;
        }
        while (idx < len && str[idx] >= '0' && str[idx] <= '9') {
            num = num*10 + str[idx] - '0';
            if (flag == 1 && num >= INT_MAX)
                return INT_MAX;
            if (flag == -1 && num*flag <= INT_MIN)
                return INT_MIN;
            idx++;
        }
        num = flag * num;
        return static_cast<int>(num);
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
