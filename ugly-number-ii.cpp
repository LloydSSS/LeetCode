// https://leetcode.com/problems/ugly-number-ii/
// 使用一个数组保留所有丑数，并且记录当前的最大值，三个指针分别代表2,3,5遍历过得元素，每次前进指针，直到元素*2,3,5大于最大值，比较三者的最小值，即是下一个丑数

#include "lc.h"

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> vec;
        vec.push_back(1);
        int mx = 1;
        int ix = 0, iy = 0, iz = 0;
        while (vec.size() < n) {
            mx = vec.back();
            int x = vec[ix]*2, y = vec[iy]*3, z = vec[iz]*5;
            while (x <= mx) {
                ix++;
                x = vec[ix]*2;
            }
            while (y <= mx) {
                iy++;
                y = vec[iy]*3;
            }
            while (z <= mx) {
                iz++;
                z = vec[iz]*5;
            }
            int minxyz = min(min(x, y), z);
            vec.push_back(minxyz);
        }
        return vec[n-1];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
