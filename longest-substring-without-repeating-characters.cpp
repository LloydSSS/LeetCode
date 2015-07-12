// http://www.lintcode.com/en/problem/longest-substring-without-repeating-characters
// Time O(n)
// 滑动窗口，用一个hash map纪录字符是否使用过

#include "lintcode.h"

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer
     */
    int lengthOfLongestSubstring(string s) {
        vector<bool> used(256, false);
        int left = 0, right = 0;
        int ans = 0;
        while (left <= right && right < s.size()) {
            if (!used[s[right]]) {
                used[s[right]] = true;
                right++;
                ans = max(ans, right-left);
            } else {
                used[s[left]] = false;
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
