// https://leetcode.com/problems/word-break-ii/

#include "lc.h"

class Solution {
public:
    unordered_set<string> unmatch;
    bool helper(string s, unordered_set<string> &dict, int start, string ans, vector<string> &res) {
        if (start >= s.size()) {
            res.push_back(ans);
            return true;
        }
        bool flag = false;
        for (int i = start; i < s.size(); ++i) {
            string str = s.substr(start, i-start+1);
            if (dict.find(str) == dict.end()) continue;
            string suffix = s.substr(i+1);
            if (unmatch.find(suffix) != unmatch.end()) continue;

            string newans = ans;
            if (newans != "") newans += " ";
            newans += str;

            if(!helper(s, dict, i+1, newans, res))
                unmatch.insert(suffix);
            else
                flag = true;
        }
        return flag;
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> res;
        if (s.size() == 0 || dict.size() == 0) return res;

        helper(s, dict, 0, "", res);
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
