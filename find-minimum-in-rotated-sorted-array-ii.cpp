// http://www.lintcode.com/en/problem/find-minimum-in-rotated-sorted-array-ii/
// 二分查找, 左闭右闭

#include "lintcode.h"

class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int l = 0, r = num.size()-1;
        while (l < r) {
            while (num[l] == num[r] && l < r)
                l++;
            int m = (l+r) >> 1;
            if (num[m] > num[r])
                l = m+1;
            else
                r = m;
        }
        return num[l];
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v = {999,999,1000,1000,10000,0,999,999,999};
    cout << sol.findMin(v) << endl;
	return 0;
}
