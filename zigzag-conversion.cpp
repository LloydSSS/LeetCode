// https://leetcode.com/problems/zigzag-conversion/
// 找规律

#include "lc.h"

class Solution {
public:
    string convert(string s, int nRows) {
        if (s.size() <= 1 || nRows <= 1 || s.size() <= nRows) return s;
        int len = s.size();
        string t;
        for (int r = 0; r < nRows; ++r) {
            int index = r;
            t += s[index];
            for (int k = 1; index < len; ++k) {
                if (r == 0 || r == nRows-1)
                    index += nRows*2-2;
                else {
                    if (k % 2 == 1)
                        index += 2*nRows-2*r-2;
                    else
                        index += 2*r;
                }
                if (index < len)
                    t += s[index];
            }
        }
        return t;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
