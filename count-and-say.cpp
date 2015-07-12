// http://www.lintcode.com/en/problem/count-and-say/
// 寻找连续字符出现的长度然后进行转换

#include "lintcode.h"

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            string tmp(s);
            s = "";
            for (int i = 0; i < tmp.size();) {
                char c = tmp[i];
                int len = 1;
                while (len+i < tmp.size() && tmp[i+len] == c)
                    len++;
                s += to_string(len) + c;
                i += len;
            }
        }
        return s;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
