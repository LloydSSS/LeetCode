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
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int idx = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[idx])
                nums[++idx] = nums[i];
        }
        nums.erase(nums.begin()+idx+1, nums.end());
        return idx+1;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
