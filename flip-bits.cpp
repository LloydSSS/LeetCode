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
    /**
     *@param a, b: Two integer
     *return: An integer
     */
    int countBit(int n) {
    	int ans = 0;
    	while (n) {
    		ans++;
    		n = n&(n-1);
    	}
    	return ans;
    }
    int bitSwapRequired(int a, int b) {
    	return countBit(a^b);
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	cout << sol.bitSwapRequired(31, 14) << endl;
	return 0;
}