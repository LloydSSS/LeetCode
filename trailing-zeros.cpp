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
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        if (n < 5) return 0;
        long long ans = 0;
        for (long long i = 5; i <= n; i*=5) {
        	ans += n/i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	cout << sol.trailingZeros(105) << endl;
	return 0;
}