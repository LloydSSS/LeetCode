// http://www.lintcode.com/en/problem/longest-consecutive-sequence/
// https://leetcode.com/problems/longest-consecutive-sequence/
// 将数字放在hash table里面，对每个数字进行左右扩展，寻找连续长度，并删掉访问过的数字

#include "lc.h"

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> ust;
        for (int i = 0; i < num.size(); ++i)
            ust.insert(num[i]);
        int ans = 0;
        for (int i = 0; i < num.size(); ++i) {
            ans = max(ans, find_bound(ust, num[i]));
        }
        return ans;
    }

    int find_bound(unordered_set<int> &ust, int x) {
        if (ust.find(x) != ust.end())
            return 0;
        int len = 1;
        int upper = x+1;
        while (ust.find(upper) != ust.end()) {
            len++;
            ust.erase(upper++);
        }
        int lower = x-1;
        while (ust.find(lower) != ust.end()) {
            len++;
            ust.erase(lower--);
        }
        return len;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
