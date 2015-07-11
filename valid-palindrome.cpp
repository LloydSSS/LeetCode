// http://www.lintcode.com/en/problem/valid-palindrome/
// 水
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

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
