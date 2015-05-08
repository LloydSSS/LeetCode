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

class Solution {
public:
    int sqrt(int x) {
        int l = 0, r = x >= 4 ? x/2 : x;
        while (l+1 < r) {
            long long mid = (l+r)/2;
            if (mid*mid == x)
                return mid;
            else if (mid*mid < x)
                l = mid;
            else
                r = mid-1;
        }
        if (r*r <= x)
            return r;
        return l;
    }
};


int main(int argc, char const *argv[]) {

	Solution sol;
    cout << sol.sqrt(999999999) << endl;
	return 0;
}
