#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class VersionControl {
    public:
    static bool isBadVersion(int k);
};
bool VersionControl::isBadVersion(int k) { return true; }

/**
 * class VersionControl {
 *     public:
 *     static bool isBadVersion(int k);
 * }
 * you can use VersionControl::isBadVersion(k) to judge wether
 * the kth code version is bad or not.
*/
class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
        int l = 1, r = n+1;
        while (l < r) {
            int m = (l+r) >> 1;
            if (VersionControl::isBadVersion(m))
                r = m;
            else
                l = m+1;
        }
        return l;
    }
};



int main(int argc, char const *argv[]) {

	Solution sol;
	return 0;
}
