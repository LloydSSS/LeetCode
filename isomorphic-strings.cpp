// https://leetcode.com/problems/isomorphic-strings/
// hash map

#include "lc.h"

class Solution {
 public:
     bool isIsomorphic(string s, string t) {
         map<char, char> mps;
         map<char, char> mpt;
         char cs = 0, ct = 0;
         for (int i = 0; i < s.size(); ++i) {
             if (mps.find(s[i]) == mps.end()) {
                 mps[s[i]] = cs;
                 s[i] = cs++;
             } else
                 s[i] = mps[s[i]];
             if (mpt.find(t[i]) == mpt.end()) {
                 mpt[t[i]] = ct;
                 t[i] = ct++;
             } else
                 t[i] = mpt[t[i]];
         }
         return s == t;
     }
 };

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
