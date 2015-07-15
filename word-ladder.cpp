// http://www.lintcode.com/en/problem/word-ladder/
// https://leetcode.com/problems/word-ladder/
// bfs，使用hash table纪录遍历过的词

#include "lc.h"

class Solution {
public:
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return an integer
      */
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> used;
        queue<pair<string, int> > qu;
        qu.push(make_pair(start, 1));
        while (!qu.empty()) {
            pair<string, int> pr = qu.front();
            qu.pop();
            string str = pr.first;
            int len = pr.second;
            if (str == end)
                return len;
            used.insert(str);
            for (int i = 0; i < str.size(); ++i) {
                string tstr = str;
                for (char c = 'a'; c <= 'z'; ++c) {
                    tstr[i] = c;
                    if (used.find(tstr) != used.end() ||
                        dict.find(tstr) == dict.end())
                        continue;
                    used.insert(tstr);
                    qu.push(make_pair(tstr, len+1));
                }
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
