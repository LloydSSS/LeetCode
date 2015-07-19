// http://www.lintcode.com/en/problem/subarray-sum/
// a. Time:O(n2) Space:O(n) 枚举头指针和尾指针
// b. Time:O(n) Space:O(n) 子数组等于两个从头开始的数组的差，使用hashmap纪录从头开始数组的和及他们的下标，当有遇到和存在在hashmap的时候表明有两个从头开始的数组和相等，即，差为0

#include "lc.h"

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number
     *          and the index of the last number
     */
    vector<int> subarraySum(vector<int> nums){
        vector<int> res(2, -1);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == 0) {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
            sum = 0;
        }
        return res;
    }
    vector<int> subarraySumHash(vector<int> nums){
        unordered_map<int, int> hash;
        vector<int> res(2, -1);
        int sum = 0;
        hash[0] = -1;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (hash.find(sum) != hash.end()) {
                res[0] = hash[sum]+1;
                res[1] = i;
                break;
            } else
                hash[sum] = i;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
