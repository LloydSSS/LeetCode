// http://www.lintcode.com/en/problem/add-binary/
// https://leetcode.com/problems/add-binary/
// 水

#include "lc.h"

class Solution {
public:
    /**
     * @param a a number
     * @param b a number
     * @return the result
     */
    string addBinary(string& a, string& b) {
        string ans;
        int carry = 0;
        int len = max(a.size(), b.size());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for (int i = 0; i < len; i++) {
            int ai = (i >= a.size() || a[i]=='0') ? 0 : 1;
            int bi = (i >= b.size() || b[i]=='0') ? 0 : 1;
            int cn = (ai + bi + carry) % 2;
            carry = (ai + bi + carry) / 2;
            ans += cn + '0';
        }
        if (carry == 1)
            ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
