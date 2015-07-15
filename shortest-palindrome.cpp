// https://leetcode.com/problems/shortest-palindrome/
// 先找到以输入字符串头起始的最长回文子串，然后将结尾逆序接到字符串头

#include "lc.h"

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() <= 1) return s;
        // int len = s.size()-1;
        // while (!isPalindrome(s, 0, len))
        //     len--;
        int len = manacher(s);
        string tail = s.substr(len);
        reverse(tail.begin(), tail.end());
        return tail + s;
    }

    int manacher(string s) {
        if (s.size() == 0) return 0;
        string t = transform(s);
        int len = t.size();
        vector<int> p(len, 1);
        int id = 0;
        int center = 0, mx = 0;
        int ans = 0;
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
            if (i-p[i] == 0)
                ans = p[i];
            if (p[i] > p[id]) {
                id = i;
            }
        }
        return ans;
        //return s.substr(id/2-p[id]/2, p[id]);
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
