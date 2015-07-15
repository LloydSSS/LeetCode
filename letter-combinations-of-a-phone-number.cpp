// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// 水

#include "lc.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> dict;
        dict['2'] = "abc";
        dict['3'] = "def";
        dict['4'] = "ghi";
        dict['5'] = "jkl";
        dict['6'] = "mno";
        dict['7'] = "pqrs";
        dict['8'] = "tuv";
        dict['9'] = "wxyz";
        vector<string> vec;

        if (digits.size() == 0) {
            vec.push_back("");
            return vec;
        }
        vector<string> tmp_vec = letterCombinations(digits.substr(1));
        for (int i = 0; i < dict[digits[0]].size(); ++i) {
            for (int j = 0; j < tmp_vec.size(); ++j) {
                vec.push_back(dict[digits[0]][i] +tmp_vec[j]);
            }
        }
        return vec;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
