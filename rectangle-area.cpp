// https://leetcode.com/problems/rectangle-area/
// 找到公共部分的面积，用总面积减去公共部分的面积

#include "lc.h"

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int ans = 0;
        ans += (C-A)*(D-B) + (G-E)*(H-F);
        int A1 = max(A, E), B1 = max(B, F), C1 = min(C, G), D1 = min(D, H);
        if (C1 > A1 && D1 > B1)
            ans -= (C1-A1)*(D1-B1);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
