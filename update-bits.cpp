// http://www.lintcode.com/en/problem/update-bits/
// 先设置mask，然后进行|操作，注意int 左移32位无定义

#include "lc.h"

class Solution {
public:
    /**
     *@param n, m: Two integer
     *@param i, j: Two bit positions
     *return: An integer
     */
    int updateBits2(int n, int m, int i, int j) {
    	bitset<32> bleft(~0);
    	bleft <<= (j+1);
    	bitset<32> bright(~0);
    	bright >>= (32-i);
    	bitset<32> bmask = bleft | bright;
    	bitset<32> bn(n);
    	bitset<32> bm(m);
    	bitset<32> ans = (bn&bmask)|(bm<<i);
    	return ans.to_ulong();
    }

    // int 左移32位无定义
    int updateBits(int n, int m, int i, int j) {
    	long long allOne = ~0;
    	long long left = (allOne)<<(j+1);
    	long long right = (1<<i)-1;
    	int mask = left | right;
    	return ((n&mask)|m<<i);
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;

	cout << sol.updateBits(-521, 0, 31, 31) << endl;
	cout << sol.updateBits(1024,21,2,6) << endl;

	return 0;
}
