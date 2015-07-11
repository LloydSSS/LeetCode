// http://www.lintcode.com/zh-cn/problem/valid-number/
// a. 状态机
// b. 条件判断
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
     * @param s the string that represents a number
     * @return whether the string is a valid number
     */
    bool isNumber(string &s) {
        enum InputType {
            INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXPONENT,   // 5

            NUM_INPUTS  // 6
        };
        // -1代表无效状态，表示不能接受该输入类型
        // inv,space,+-,1234,.,eE
        int transitionTable[][NUM_INPUTS] = {
            -1,  0,  1,  2,  3, -1,     // next states for state 0，有空格，可以读入space, sign, digit, dot
            -1, -1, -1,  2,  3, -1,     // next states for state 1, 有符号，可以读入dot, digit
            -1,  5, -1,  2,  4,  6,     // next states for state 2, 有数字，可以读入dot，digit, exp, 接受space进入结束状态
            -1, -1, -1,  4, -1, -1,     // next states for state 3，有小数点，可以读入digit,之后不能在接收小数点
            -1,  5, -1,  4, -1,  6,     // next states for state 4，小数点＋数字or数字＋小数点，可以读入exp，digit，接受space进入结束状态
            -1,  5, -1, -1, -1, -1,     // next states for state 5, 结束状态，只能接受空格
            -1, -1,  7,  8, -1, -1,     // next states for state 6, 有e符号，可以读入sign, digit
            -1, -1, -1,  8, -1, -1,     // next states for state 7，e+sign，只能读入digit
            -1,  5, -1,  8, -1, -1,     // next states for state 8，e+数字，只能读入digit
        };

        int state = 0;
        int idx = 0;
        int len = s.size();
        while (idx < len) {
            InputType inputType = INVALID;
            if (isspace(s[idx]))
                inputType = SPACE;
            else if (s[idx] == '+' || s[idx] == '-')
                inputType = SIGN;
            else if (isdigit(s[idx]))
                inputType = DIGIT;
            else if (s[idx] == '.')
                inputType = DOT;
            else if (s[idx] == 'e' || s[idx] == 'E')
                inputType = EXPONENT;

            state = transitionTable[state][inputType];

            if (state == -1)
                return false;
            else
                idx++;
        }
        return state == 2 || state == 4 || state == 5 || state == 8;
    }

    bool isNumber(const char *s) {
        while (*s == ' ') ++s;
        if (*s == '+' || *s == '-') ++s;
        bool hasdot = false, hasspace = false, hasexp = false;
        bool res = false;
        while (*s != '\0') {
            if (*s >= '0' && *s <= '9') {
                if (hasspace) return false;
                res = true;
                ++s;
            } else if (*s == '.') {
                if (hasdot || hasspace || hasexp) return false;
                hasdot = true;
                ++s;
            } else if (*s == 'e' || *s == 'E') {
                if (hasspace || hasexp || !res) return false;
                hasexp = true;
                res = false;
                ++s;
                if (*s == '+' || *s == '-') ++s;
            } else if (*s == ' ') {
                hasspace = true;
                ++s;
            } else {
                return false;
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
