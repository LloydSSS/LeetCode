// http://www.lintcode.com/en/problem/partition-array/
// 两边向中间partation
// 从左向右一个方向partation:注意有很多条件，不存在k，都大于k都小于k，多个k

#include "lc.h"

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int l = 0, r = nums.size()-1;
        while (l < r) {
            while (l <= r && nums[l] < k) l++;
            while (r >= l && nums[r] >= k) r--;
            if (l < r)
                swap(nums[l], nums[r]);
        }
        return l;
    }
};

class Solution2 {
public:
    int partitionArray(vector<int> &nums, int k) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            if (nums[l] < k)
                l++;
            else {
                swap(nums[l], nums[r]);
                r--;
            }
        }
        return l;
    }
};

class Solution3 {
public:
    int partitionArray(vector<int> &nums, int k) {
        if (nums.size() == 0) return 0;
        int l = 0, r = nums.size()-1;
        bool ispivotfound = false; // avoid duplicate k exist
        for (int i = l; i <= r; ++i) {
            if (nums[i] < k) {
                swap(nums[i], nums[l++]);
            } else if (!ispivotfound && nums[i] == k) {
                swap(nums[i--], nums[r]);
                ispivotfound = true;
            }
        }
        if (l < r)
            swap(nums[l], nums[r]);
        return l;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
