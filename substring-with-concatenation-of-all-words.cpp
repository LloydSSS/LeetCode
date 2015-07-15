// https://leetcode.com/problems/substring-with-concatenation-of-all-words
// 暴力匹配
// TODO:单词是定长的，所以和字符一样和Longest Substring Without Repeating Characters思路差不多，可以做到线性时间

#include "lc.h"

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (L.size() == 0) return res;
        int num = L.size();
        int len = L[0].size();
        map<string, int> word;
        map<string, int> mp;
        for (int i = 0; i < num; ++i)
            word[L[i]]++;
        for (int i = 0; i < S.size()-num*len+1; ++i) {
            mp.clear();
            int j;
            for (j = 0; j < num; ++j) {
                string w = S.substr(i+j*len, len);
                mp[w]++;
                if (mp[w] > word[w]) break;
            }
            if (j == num) {
                res.push_back(i);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
