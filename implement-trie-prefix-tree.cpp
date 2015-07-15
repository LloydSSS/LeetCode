// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <lc.h>

class TrieNode {
public:
    bool isword;
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
        p->isword = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (auto c : word) {
            int ic = c-'a';
            if (p->child[ic] == nullptr)
                return false;
            p = p->child[ic];
        }
        return p->isword;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (auto c : prefix) {
            int ic = c-'a';
            if (p->child[ic] == nullptr)
                return false;
            p = p->child[ic];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
int main(int argc, char const *argv[]) {
    return 0;
}
