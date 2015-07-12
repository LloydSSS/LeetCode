// http://www.lintcode.com/en/problem/longest-substring-with-at-most-k-distinct-characters
// Time O(n)
// 滑动窗口，用一个hash map纪录字符的使用数量及次数

#include "lintcode.h"

class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> used(256, 0);
        int left = 0, right = 0;
        int ans = 0;
        while (left <= right && right < s.size()) {
            if (k > 0 || used[s[right]] > 0) {
                if (used[s[right]] == 0)
                    k--;
                used[s[right]]++;
                right++;
                ans = max(ans, right-left);
            } else {
                used[s[left]]--;
                if (used[s[left]] == 0)
                    k++;
                left++;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
