#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
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
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> maxdp(nums.size(), INT_MIN);
        vector<int> mindp(nums.size(), INT_MAX);

        int ans = maxdp[0] = mindp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            maxdp[i] = max(max(maxdp[i-1]*nums[i], mindp[i-1]*nums[i]), nums[i]);
            mindp[i] = min(min(maxdp[i-1]*nums[i], mindp[i-1]*nums[i]), nums[i]);
            if (maxdp[i] > ans)
                ans = maxdp[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}