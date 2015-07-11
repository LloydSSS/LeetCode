// http://www.lintcode.com/en/problem/binary-search-tree-iterator/#
// Space:O(logn)
// stack
// Space:O(1)
// threading
// 见morris遍历
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;


// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        while (root != nullptr) {
            st.push(root);
            root = root->left;
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return !st.empty();
    }

    //@return: return next node
    TreeNode* next() {
        TreeNode *nt = st.top();
        st.pop();
        TreeNode *p = nt->right;
        while (p != nullptr) {
            st.push(p);
            p = p->left;
        }
        return nt;
    }

    stack<TreeNode *> st;
};

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution2 {
public:
    //@param root: The root of binary tree.
    Solution2(TreeNode *root) {
        iter = nullptr;
        thread(root);
    }

    // 右中左，最后一个线索化的元素就是起始元素，纪录每个元素的后一个元素
    void thread(TreeNode *root) {
        if (root == nullptr) return;
        if (root->right == nullptr) root->right = iter;
        else thread(root->right);
        iter = root;
        thread(root->left);
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return iter != nullptr;
    }

    //@return: return next node
    TreeNode* next() {
        TreeNode *nt = iter;
        iter = iter->right;
        while (iter != nullptr && iter->left != nullptr
            && iter->left->val > nt->val)
            iter = iter->left;
        return nt;
    }

    TreeNode *iter;
};


int main(int argc, char const *argv[]) {
    Solution sol(NULL);
    return 0;
}
