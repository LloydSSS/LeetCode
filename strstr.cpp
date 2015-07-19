// http://www.lintcode.com/en/problem/strstr/
// 暴力匹配
// kmp

#include "lc.h"

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source == nullptr || target == nullptr) return -1;
        if (*target == '\0') return 0;

        int slen = strlen(source);
        int tlen = strlen(target);
        int i = 0, j = 0;
        while (i < slen && j < tlen) {
        	if (source[i] == target[j]) {
        		i++;
        		j++;
        	} else {
        		i = i-j+1;
        		j = 0;
        	}
        }
        if (j == tlen)
        	return i-j;
        else
	        return -1;
    }

    int kmp(const char *s, const char *p) {
        if (s == nullptr || p == nullptr) return -1;
        int slen = strlen(s);
        int plen = strlen(p);
        if (slen == 0) return plen == 0 ? 0 : -1;
        if (plen == 0) return 0;

        vector<int> nt(plen+1);
        get_next(p, nt);

        int i = 0, j = 0;
        while (i < slen) {
            if (j == -1 || s[i] == p[j]) {
                ++i;
                ++j;
            } else {
                j = nt[j];
            }
            if (j == plen) {
                return i-j;
            }
        }
        return -1;
    }

    void get_next(const char *p, vector<int> &nt) {
        int i = 0, j = -1;
        nt[i] = j;
        while (i < strlen(p)) {
            if (j == -1 || p[i] == p[j]) {
                nt[++i] = ++j;
            } else {
                j = nt[j];
            }
        }
    }

    int kmp2(const char *s, const char *p) {
        if (s == nullptr || p == nullptr) return -1;
        int slen = strlen(s);
        int plen = strlen(p);
        if (slen == 0) return plen == 0 ? 0 : -1;
        if (plen == 0) return 0;

        vector<int> nt(plen+1);
        get_next2(p, nt);

        int i = 0, j = 0;
        while (i < slen) {
            while (j != -1 && s[i] != p[j]) j = nt[j];
            ++i, ++j;
            if (j == plen) {
                return i-j;
            }
        }
        return -1;
    }

    void get_next2(const char *p, vector<int> &nt) {
        int i = 0, j = -1;
        nt[i] = j;
        while (i < strlen(p)) {
            while (j != -1 && p[i] != p[j])
                j = nt[j];
            nt[++i] = ++j;
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    cout << sol.strStr("source", "target") << endl;
	cout << sol.kmp("source", "source") << endl;
	return 0;
}
