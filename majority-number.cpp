#include <iostream>
#include <algorithm>
#include <vector>
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
     * @param nums: A list of integers
     * @return: The majority number
     */
    // sort
    // stack
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
