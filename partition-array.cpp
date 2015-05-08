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
    int partitionArray(vector<int> &nums, int k) {
        int l = 0, r = nums.size()-1;

        while (true) {
            while (l <= r && nums[l] < k) l++;
            while (r >= l && nums[r] >= k) r--;
            if (l >= r) break;
            swap(nums[l], nums[r]);
        }
        return l;
    }
};


int main(int argc, char const *argv[]) {

	Solution sol;

	return 0;
}
