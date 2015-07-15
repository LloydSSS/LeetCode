// https://leetcode.com/problems/add-and-search-word-data-structure-design/
// 当遇见.的时候搜索每个子节点
#include "lc.h"

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
        return search(word, root, 0);
    }

    bool search(string &word, TrieNode *p, int idx) {
        if (p == nullptr) return false;
        if (idx == word.size()) return p->isword;

        if (word[idx] == '.') {
            for (auto q : p->child) {
                if (search(word, q, idx+1))
                    return true;
            }
            return false;
        } else {
            return search(word, p->child[word[idx]-'a'], idx+1);
        }
    }
private:
    TrieNode* root;
};

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        root.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return root.search(word);
    }

private:
    Trie root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
int main(int argc, char const *argv[]) {
    return 0;
}
