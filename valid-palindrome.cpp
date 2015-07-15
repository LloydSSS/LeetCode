// http://www.lintcode.com/en/problem/valid-palindrome/
// 左右指针遍历

#include "lc.h"

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    bool isPalindrome(string& s) {
        int l = 0, r = s.size()-1;
        while (l < r) {
            while (!isalnum(s[l])) l++;
            while (!isalnum(s[r])) r--;
            if (l >= r)
                break;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            l++, r--;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
