// http://www.lintcode.com/en/problem/fast-power/
// 分治,基础题

#include "lintcode.h"

class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
    	if (a == 0) return 0;
    	if (n == 0) return 1%b;
    	if (n == 1) return a%b;

    	long long ans = fastPower(a, b, n/2);
    	ans = (ans*ans)%b;
        if (n%2 == 1) {
        	ans = (ans*(a%b))%b;
        }
        return ans;
    }

};

int main(int argc, char const *argv[]) {
	Solution sol;

	cout << sol.fastPower(109, 10000007, 1000001) << endl;

	return 0;
}
