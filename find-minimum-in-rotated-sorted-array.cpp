// http://www.lintcode.com/en/problem/find-minimum-in-rotated-sorted-array/
// 二分查找, 左闭右闭

#include "lintcode.h"

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
            if (num[m] > num[r])
                l = m+1;
            else
                r = m;
            // if (num[l] > num[m])
            //     r = m;
            // else if (num[m] > num[r])
            //     l = m+1;
            // else
            //     break;
        }
        return num[l];
    }
};



int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v;
    v.push_back(6);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    cout << sol.findMin(v) << endl;
	return 0;
}
