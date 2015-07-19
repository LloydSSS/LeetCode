// https://leetcode.com/problems/rotate-array/
// 两次reverse

#include "lc.h"

class Solution {
public:
    void reverse(int nums[], int s, int t) {
        while (s<t) {
            swap(nums[s], nums[t]);
            s++,t--;
        }
    }
    void rotate(int nums[], int n, int k) {
        k = k % n;
        if (k == 0) return;
        reverse(nums, 0, n-k-1);
        reverse(nums, n-k, n-1);
        reverse(nums, 0, n-1);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
