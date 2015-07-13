// http://www.lintcode.com/en/problem/product-of-array-exclude-itself/
// 计算从左向右，以及从右向左的product

#include "lintcode.h"

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        vector<long long> left(nums.size(), 1);
        vector<long long> right(nums.size(), 1);
        vector<long long> res(nums.size(), 1);

        if (nums.size() <= 1) return res;

        left[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            left[i] = left[i-1]*nums[i];
        }
        right[nums.size()-1] = nums[nums.size()-1];
        for (int i = nums.size()-2; i >= 0; --i) {
            right[i] = right[i+1]*nums[i];
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0)
                res[i] = right[i+1];
            else if (i == nums.size()-1)
                res[i] = left[i-1];
            else
                res[i] = left[i-1]*right[i+1];
        }
        return res;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
