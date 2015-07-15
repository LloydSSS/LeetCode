// https://leetcode.com/problems/powx-n/
// 分治

#include "lc.h"

class Solution {
public:
    double pow(double x, int n) {
        if (n < 0) {
            x = 1/x;
            n = -n;
        }
        if (n == 0 && x !=0)
            return 1;
        else {
            double y = pow(x, n/2);
            if (n%2 == 1)
                return y*y*x;
            else
                return y*y;
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
