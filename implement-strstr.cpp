// https://leetcode.com/problems/implement-strstr/
// kmp

#include "lc.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() == 0) return needle.size() == 0 ? 0 : -1;
        if (needle.size() == 0) return 0;

        vector<int> nt(needle.size()+1);
        get_next(needle, nt);
        int i = 0, j = 0;
        while (i < haystack.size()) {
            if (j == -1 || haystack[i] == needle[j])
                ++i,++j;
            else
                j = nt[j];
            if (j == needle.size())
                return i - j;
        }
        return -1;
    }

    void get_next(string needle, vector<int> &nt) {
        int i = 0, j = -1;
        nt[i] = j;
        while (i < needle.size()) {
            if (j == -1 || needle[i] == needle[j])
                nt[++i] = ++j;
            else
                j = nt[j];
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
