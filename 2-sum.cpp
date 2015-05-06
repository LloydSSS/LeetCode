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
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> mp;
        vector<int> res(2, -1);

        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            mp[nums[i]] = i;
        }
        for (int i = 0; i < len; ++i) {
            if (mp.find(target-nums[i]) != mp.end()) {
                res[0] = i+1;
                res[1] = mp[target-nums[i]]+1;
                break;
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
