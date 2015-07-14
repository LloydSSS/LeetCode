// http://www.lintcode.com/en/problem/unique-characters/
// hash_table 记录每个字符是否出现过

#include "lintcode"

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        bool mp[256] = {false};
        for (int i = 0; i < str.size(); ++i)
            if (!mp[str[i]]) mp[str[i]] = true;
            else return false;
        return true;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}