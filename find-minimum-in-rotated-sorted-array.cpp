// http://www.lintcode.com/en/problem/find-minimum-in-rotated-sorted-array/
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// 二分查找, 左闭右闭

#include "lc.h"

class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int l = 0, r = num.size()-1;
        while (l < r) {
            int m = (l+r) >> 1;
            if (num[m] < num[r])
                r = m;
            else
                l = m+1;
        }
        return num[l];
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v = {6,1,2,3,4,5};
    cout << sol.findMin(v) << endl;
	return 0;
}
