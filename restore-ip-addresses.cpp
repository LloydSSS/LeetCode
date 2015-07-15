// https://leetcode.com/problems/restore-ip-addresses/
// dfs＋剪枝

#include "lc.h"

class Solution {
public:
    vector<string> ans;
    vector<string> ip;

    bool is_valid(string s) {
        if (s.size() == 1)
            return "0" <= s && s <= "9";
        if (s.size() == 2)
            return "10" <= s && s <= "99";
        if (s.size() == 3)
            return "100" <= s && s <= "255";
        return false;
    }
    void dfs(int dep, int max_dep, string s) {
        if (dep == max_dep) {
            string term = ip[0];
            for (int i = 1; i < 4; ++i)
                term += "." + ip[i];
            ans.push_back(term);
            return;
        }
        for (int i = 1; i < 4; ++i) {
            string seg = s.substr(0, i);
            if (is_valid(seg) && s.size() - i <= (max_dep-dep-1)*3 && s.size() - i >= max_dep-dep-1) {
                ip[dep] = seg;
                dfs(dep+1, max_dep, s.substr(i, s.size()-i));
            }
        }

    }
    vector<string> restoreIpAddresses(string s) {
        ip = vector<string>(4);
        dfs(0, 4, s);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
