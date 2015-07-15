// https://leetcode.com/problems/contains-duplicate-ii/
// multiset+lower_bound，保持bst里面只有k个数，每加一个就删除一个

#include "lc.h"

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> bst;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) bst.erase(bst.find(nums[i-k-1]));
            auto lb = bst.lower_bound(nums[i]-t);
            if (lb != bst.end() && *lb - nums[i] <= t) return true;
            bst.insert(nums[i]);
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
