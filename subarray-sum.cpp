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
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
