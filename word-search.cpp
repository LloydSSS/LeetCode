// http://www.lintcode.com/en/problem/word-search/
// a. dfs暴搜
#include "lintcode.h"

class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        if (word.size() == 0) return true;
        m = board.size();
        if (m == 0) return false;
        n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                set<pair<int, int> > visited;
                if (dfs(board, i, j, word, visited))
                    return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char> > &board, int i, int j,
            string word, set<pair<int, int> > &visited) {
        if (word.size() == 0) return true;
        if (i < 0 || i >= m || j < 0 || j >= n
            || visited.find(make_pair(i, j)) != visited.end())
            return false;
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        visited.insert(make_pair(i, j));
        if (word[0] == board[i][j]) {
            for (auto &d : directions) {
                if (dfs(board, i+d.first, j+d.second, word.substr(1), visited))
                    return true;
            }
        }
        visited.erase(make_pair(i, j));
        return false;
    }

    int m, n;
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
