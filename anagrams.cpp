// http://www.lintcode.com/en/problem/anagrams
// hash_map key为排序后的结果，val是所有anagrams

#include "lintcode.h"

class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ans;
        unordered_map<string, vector<string> > mp;
        for (int i = 0; i < strs.size(); ++i) {
            string ss = strs[i];
            sort(ss.begin(), ss.end());
            mp[ss].push_back(strs[i]);
        }
        for (const auto &kv : mp) {
            if (kv.second.size() != 1) {
                ans.insert(ans.end(), kv.second.begin(), kv.second.end());
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
