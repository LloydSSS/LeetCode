// https://leetcode.com/problems/different-ways-to-add-parentheses/
// 枚举

#include "lc.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ans;
        if (input.empty())
            return ans;
        for (int i = 0; i < input.size(); ++i) {
            if (input[i] >= '0' && input[i] <= '9')
                continue;
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i+1));
            for (int l : left)
            for (int r : right) {
                if (input[i] == '+')
                    ans.push_back(l+r);
                else if (input[i] == '-')
                    ans.push_back(l-r);
                else
                    ans.push_back(l*r);
            }
        }
        if (ans.size() == 0)
            ans.push_back(stoi(input));
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
	return 0;
}
