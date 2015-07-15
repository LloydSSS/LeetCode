// http://www.lintcode.com/en/problem/word-ladder/
// bfs搜索, 同时建立反向路径，再dfs搜索，寻找路径
// http://www.tuicool.com/articles/eaQNNr

#include "lc.h"

class Solution {
public:
    vector<vector<string> > res;
    unordered_map<string, unordered_set<string>> path;
    int len;
    bool bfs(string start, string end, unordered_set<string> &dict) {
        typedef pair<string, int> qnode;
        queue<qnode> q;
        q.push(qnode(start, 1));
        path[start].insert(start);
        vector<unordered_set<string>> candidates(2);
        int cur = 0;
        int prev = 1;
        candidates[cur].insert(start);
        while (candidates[cur].size() != 0 && candidates[cur].find(end) == candidates[cur].end()) {
            prev = !prev;
            cur = !cur;
            for (string s : candidates[prev])
                dict.erase(s);
            candidates[cur].clear();
            for (string s : candidates[prev]) {
                for (int i = 0; i < s.size(); ++i) {
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (s[i] == c) continue;
                        string t = s;
                        t[i] = c;

                        if (dict.find(t) == dict.end()) continue;
                        candidates[cur].insert(t);
                        path[t].insert(s);
                        //cout << s << "-->" << t << endl;

                    }
                }
            }
        }
        return candidates[cur].find(end) != candidates[cur].end();
    }

    void dfs(string start, string end, unordered_set<string> &dict, int d, vector<string > p) {
        if (end == start) {
            reverse(p.begin(), p.end());
            res.push_back(p);
            return;
        }
        unordered_set<string> pre = path[end];
        for (auto str : pre) {
            p.push_back(str);
            dfs(start, str, dict, d, p);
            p.pop_back();
        }
    }
    /**
      * @param start, a string
      * @param end, a string
      * @param dict, a set of string
      * @return a list of lists of string
      */
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        if (start == end) {
            res.push_back(vector<string>(1, start));
            return res;
        }
        if (bfs(start, end, dict)) {
            vector<string> p;
            p.push_back(end);
            dfs(start, end, dict, 1, p);
        }

        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
