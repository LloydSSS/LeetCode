// https://leetcode.com/problems/valid-anagram/
// hash表

#include "lc.h"

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> counts(256), countt(256);
        for (auto c : s) counts[c]++;
        for (auto c : t) countt[c]++;
        for (size_t i = 0; i < counts.size(); ++i) {
            if (counts[i] != countt[i])
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
