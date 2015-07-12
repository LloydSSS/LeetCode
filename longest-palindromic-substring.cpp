// http://www.lintcode.com/en/problem/longest-palindromic-substring
// Time O(n2)
// dp
// Time O(n)
// manacher

#include "lintcode.h"

class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string s) {
        if (s.size() == 0) return string();
        string t = transform(s);
        int len = t.size();
        vector<int> p(len, 1);
        int id = 0;
        int center = 0, mx = 0;
        for (int i = 0; i < len; ++i) {
            if (mx > i)
                p[i] = min(p[2*center-i], mx-i);
            while (i-p[i] >= 0  && p[i]+i < len && t[i-p[i]] == t[i+p[i]])
                p[i]++;
            p[i]--;
            if (i+p[i] > mx) {
                mx = i+p[i];
                center = i;
            }
            if (p[i] > p[id]) {
                id = i;
            }
        }
        return s.substr(id/2-p[id]/2, p[id]);
    }

    string transform(const string &s) {
        string t("#");
        for (int i = 0; i < s.size(); ++i) {
            t += s[i];
            t += "#";
        }
        return t;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
