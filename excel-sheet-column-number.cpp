// https://leetcode.com/problems/excel-sheet-column-number/

#include "lc.h"

class Solution {
public:
    int titleToNumber(string s) {
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            int a = s[i] - 'A' + 1;
            ret = ret * 26 + a;
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
