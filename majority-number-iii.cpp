// Majority Number III
// http://www.lintcode.com/en/problem/majority-number-iii/
// k抵消，注意最后要重新统计一次
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
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
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            auto it = hash.find(nums[i]);
            if (it == hash.end()) {
                hash[nums[i]] = 1;
                if (hash.size() == k) {
                    for (auto hit = hash.begin(); hit != hash.end();) {
                        if (--(hit->second) == 0) {
                            hit = hash.erase(hit);
                        }
                        else {
                            hit++;
                        }
                    }
                }
            }
            else {
                it->second++;
            }
        }
        for (auto hit = hash.begin(); hit != hash.end(); hit++) {
            hit->second = 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            auto it = hash.find(nums[i]);
            if (it != hash.end()) {
                it->second++;
            }
        }
        int ret = 0;
        int max_count = 0;
        for (auto hit = hash.begin(); hit != hash.end(); hit++) {
            if (hit->second > max_count) {
                max_count = hit->second;
                ret = hit->first;
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
