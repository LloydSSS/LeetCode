// http://www.lintcode.com/en/problem/word-break/
// https://leetcode.com/problems/word-break/
// dp[i] == true means [0~i] can break

#include "lc.h"

class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreakDP(string s, unordered_set<string> &dict) {
        //if (dict.size() == 0 && s == "") return true;
        vector<bool> dp(s.size()+1, false); // dp[i] == true means [0~i] can break
        dp[0] = true;
        // size_t maxL = 0, minL = INT_MAX;
        // for (unordered_set<string>::iterator usi = dict.begin();
        //     usi != dict.end(); usi++) {
        //     string str = *usi;
        //     maxL = max(maxL, str.size());
        //     minL = min(minL, str.size());
        // }

        for (int i = 0; i < s.size(); ++i) {
            if (!dp[i]) continue;
            for (unordered_set<string>::iterator usi = dict.begin();
                usi != dict.end(); usi++) {
                string str = *usi;
                int l = str.size();
                if (l+i > s.size() || dp[i+l])
                    continue;
                if (s.substr(i, l) == str) {
                    dp[i+l] = true;
                    if (i+l == s.size()) return true;
                }
            }

            // TLE
            // if (dp[i] == false && dict.find(s.substr(0, i+1)) != dict.end())
            //     dp[i] = true;
            // if (dp[i]) {
            //     for (int l = minL; l <= maxL && i+l < s.size(); ++l) {
            //         if (dict.find(s.substr(i+1, l)) != dict.end()) {
            //             dp[i+l] = true;
            //             if (i+l == s.size()) return true;
            //         }
            //     }
            // }
        }
        return dp[s.size()];
    }

    unordered_set<string> unmatch;
    bool wordBreak(string s, unordered_set<string> &dict) {
        return wordBreakDP(s, dict);
        // MLE
        if (dict.size() == 0 && s == "") return true;
        for (int i = 1; i <= s.size(); ++i) {
            string prefix = s.substr(0, i);
            if (dict.find(prefix) == dict.end()) continue;
            if (i == s.size()) return true;
            string suffix = s.substr(i);
            if (unmatch.find(suffix) != unmatch.end()) continue;
            if (wordBreak(suffix, dict)) return true;
            else {
                unmatch.insert(suffix);
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    unordered_set<string> dict;
    dict.insert("a");
    string s = "a";
    cout << sol.wordBreakDP(s, dict) << endl;
    return 0;
}
