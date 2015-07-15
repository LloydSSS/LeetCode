// http://www.lintcode.com/en/problem/flip-bits/
// 寻找a^b中1的个数

#include "lc.h"

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
