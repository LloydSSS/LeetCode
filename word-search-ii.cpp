// http://www.lintcode.com/en/problem/word-search-ii/
// a. Trie+dfs暴搜
#include "lintcode.h"

class TrieNode {
public:
    bool isword;
    string str;
    vector<TrieNode *> child;
    TrieNode() : isword(false) {
        child.assign(26, nullptr);
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (auto c : word) {
            int ic = c-'a';
            if (p->child[ic] == nullptr)
                p->child[ic] = new TrieNode();
            p = p->child[ic];
        }
        p->str = word;
        p->isword = true;
    }

    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.size() == 0) return ans;
        m = board.size();
        if (m == 0) return ans;
        n = board[0].size();

        visited.assign(m, vector<bool>(n, false));
        for (const auto &w : words)
            trie.insert(w);

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int ic = board[i][j] - 'a';
                if (trie.root->child[ic] != nullptr)
                    dfs(board, i, j, trie.root->child[ic]);
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode *p) {
        if (p->isword) {
            ans.push_back(p->str);
            p->isword = false;
        }
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        visited[i][j] = true;

        for (auto &d : directions) {
            int x = i+d.first, y = j+d.second;
            if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || p->child[board[x][y] - 'a'] == nullptr)
                continue;
            dfs(board, x, y, p->child[board[x][y] - 'a']);
        }

        visited[i][j] = false;
    }

private:
    int m;
    int n;
    Trie trie;
    vector<string> ans;
    vector<vector<bool> > visited;
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<vector<char> > board = {{'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}, {'a', 'a', 'a', 'a'}};
    vector<string> words = {"aaaaaaaaaaaa","aaaaaaaaaaaaa","aaaaaaaaaaab"};
    auto ans = sol.findWords(board, words);
    for (auto a : ans)
        cout << a << endl;
    return 0;
}
