// http://www.lintcode.com/en/problem/find-the-missing-number/
// 桶排序
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: an integer
     */
    int findMissing(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (nums[i] >= 0 && nums[i] < nums.size()
                && nums[i] != i && nums[nums[i]] != nums[i])
                swap(nums[i], nums[nums[i]]);
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) return i;
        }
        return nums.size();
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
