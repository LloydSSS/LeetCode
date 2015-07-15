// http://www.lintcode.com/en/problem/binary-search-tree-iterator/
// https://leetcode.com/problems/binary-search-tree-iterator/
// Space:O(logn)
// 使用栈先序遍历
// Space:O(1)
// threading，按照右中左的顺序进行递归线索化，最终指向第一个元素
// 见morris遍历

#include "lc.h"

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
    Solution sol(nullptr);
    return 0;
}
