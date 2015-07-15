// http://www.lintcode.com/zh-cn/problem/trapping-rain-water/
// O(n), O(n)   a.使用两个数组纪录每个位置左右的最高点，然后进行计算
// O(n), O(1)   b.两边往中间遍历，最高点不变，使用一个变量纪录第二高点，计算较低位置可以trap的雨量secHeight-heights[lower];
// O(n), O(1)   c.两遍遍历，从左向右，纪录最高的index，并纪录最高index到目前为止的block大小，如果遇到比最高index高的，则计算到目前为止trap的雨量；这样最高点往右的位置无法计算，需要从右向左遍历

#include "lc.h"

class Solution {
public:
    /**
     * @param heights: a vector of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        return trapRainWater2pass(heights);
        int left = 0;
        int right = heights.size()-1;
        int secHeight = 0;
        int ans = 0;
        while (left < right) {
            if (heights[left] < heights[right]) {
                secHeight = max(secHeight, heights[left]);
                ans += secHeight-heights[left];
                left++;
            } else {
                secHeight = max(secHeight, heights[right]);
                ans += secHeight-heights[right];
                right--;
            }
        }
        return ans;
    }

    int trapRainWater2pass(vector<int> &A) {
        int n = A.size();
        int ans = 0;
        int hid = 0;    //the highest index
        int block = 0;  //the block area
        for (int i = 1; i < n; ++i) {
            if (A[i] >= A[hid]) {
                ans += A[hid] * (i-hid-1) - block;
                block = 0;
                hid = i;
            } else
                block += A[i];
        }
        int rhid = n-1;
        block = 0;
        for (int i = n-2; i >= hid; --i) {
            if (A[i] >= A[rhid]) {
                ans += A[rhid] * (rhid-i-1) - block;
                block = 0;
                rhid = i;
            } else
                block += A[i];
        }
        return ans;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trapRainWater(v) << endl;
	return 0;
}
