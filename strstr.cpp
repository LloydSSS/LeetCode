#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source == NULL || target == NULL) return -1;
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
};


int main(int argc, char const *argv[]) {
	Solution sol;
	cout << sol.strStr("aabb", "ab") << endl;
	/* code */
	return 0;
}