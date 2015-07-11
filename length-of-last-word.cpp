// http://www.lintcode.com/en/problem/length-of-last-word/
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
     * @return the length of last word
     */
    int lengthOfLastWord(string& s) {
        int len = 0;
        int i = s.size()-1;
        while (s[i] == ' ') i--;
        while (i >= len && s[i-len] != ' ') len++;
        return len;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
