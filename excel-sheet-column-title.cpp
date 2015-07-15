// https://leetcode.com/problems/excel-sheet-column-number/

#include "lc.h"

class Solution {
public:
    string convertToTitle(int n) {
        string s;
        while (n) {
            int l = n%26;
            if (l == 0) l = 26;
            char c = l - 1 + 'A';
            n = (n-l)/26;
            s.push_back(c);
        }
        for (int i = 0; i < s.size()/2; ++i)
            swap(s[i], s[s.size()-1-i]);
        return s;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
