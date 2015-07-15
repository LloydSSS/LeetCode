// https://leetcode.com/problems/contains-duplicate-ii/
// hash table

#include "lc.h"

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            if (hash.find(nums[i]) != hash.end()) {
                if (i - hash[nums[i]] <= k) return true;
                hash[nums[i]] = i;
            }
            hash[nums[i]] = i;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
