// https://leetcode.com/problems/contains-duplicate/
// hash table

#include "lc.h"

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for (int n : nums) {
            if (hash.find(n) != hash.end()) return true;
            hash.insert(n);
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
