// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// 中序遍历，保留链表结尾

#include "lc.h"

class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) return;
        stack<TreeNode *> s;
        TreeNode *last = nullptr;
        s.push(root);
        while (!s.empty()) {
            TreeNode *node = s.top();
            s.pop();
            if (last != nullptr) {
                last->right = node;
                last->left = nullptr;
            }
            last = node;
            if (node->right != nullptr)
                s.push(node->right);
            if (node->left != nullptr)
                s.push(node->left);
        }
    }
};

class Solution2 {
public:
    void preOrder(TreeNode *root) {
        if (root == NULL) return;
        TreeNode *rn = root->right;
        if (root->left != NULL) {
            preOrder(root->left);
            TreeNode *llast = root->left;
            while (llast->right != NULL)
                llast = llast->right;
            llast->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        preOrder(rn);
    }
    void flatten(TreeNode *root) {
        preOrder(root);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
