#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int gap = INT_MAX, ans = 0;
        for (int i = 0; i < len; ++i) {
            int j = i+1, k = len-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    k--;
                } else {
                    j++;
                }
                if (abs(sum - target) < gap) {
                    gap = abs(sum - target);
                    ans = sum;
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
