// http://www.lintcode.com/en/problem/invert-binary-tree/
// https://leetcode.com/problems/invert-binary-tree/
// 水

#include "lc.h"

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) return;
        TreeNode *pn = root->left;
        root->left = root->right;
        root->right = pn;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
};

class Solution2 {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (root == nullptr) return;
        stack<TreeNode*> nodes;
        nodes.emplace(root);
        while (!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();
            swap(node->left, node->right);
            if (node->left != nullptr) {
                nodes.emplace(node->left);
            }
            if (node->right != nullptr) {
                nodes.emplace(node->right);
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
