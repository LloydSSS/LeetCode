// http://www.lintcode.com/en/problem/binary-search/
// Time, Space O(logn)
// 二分搜索，左闭右闭，注意l+r可能溢出
#include "lc.h"

class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        int l = 0, r = array.size()-1;
        while (l < r) {
            int m = l + (r-l)/2;
            if (array[m] < target)
                l = m+1;
            else
                r = m;
        }
        if (l < array.size() && array[l] == target) return l;
        return -1;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
