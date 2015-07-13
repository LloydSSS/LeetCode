// http://www.lintcode.com/en/problem/majority-number
// https://leetcode.com/problems/majority-element
// Runtime: O(n), Space: O(n) — Hash table: Maintain a hash table of the counts of each element, then find the most common one.
// Runtime: O(n log n) — Sorting: As we know more than half of the array are elements of the same value, we can sort the array and all majority elements will be grouped into one contiguous chunk. Therefore, the middle (n/2th) element must also be the majority element.
// Runtime: O(n) — Moore voting algorithm: We maintain a current candidate and a counter initialized to 0. As we iterate the array, we look at the current element x:
// If the counter is 0, we set the current candidate to x and the counter to 1.
// If the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
// After one pass, the current candidate is the majority element. Runtime complexity = O(n).
// Runtime: O(n) — Bit manipulation: We would need 32 iterations, each calculating the number of 1's for the ith bit of all n numbers. Since a majority must exist, therefore, either count of 1's > count of 0's or vice versa (but can never be equal). The majority number’s ith bit must be the one bit that has the greater count.
#include "lintcode.h"

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    // sort
    // greedy
    int majorityNumber(vector<int> nums) {
        if (nums.size() == 0)
            return 0;
        int ans = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == ans)
                cnt++;
            else {
                cnt--;
                if (cnt == 0) {
                    ans = nums[i];
                    cnt = 1;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
