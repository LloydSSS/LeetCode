// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// 完全二叉树
// 将每个节点的左孩子指向它的右孩子，右孩子指向它的兄弟的左孩子（不存在指向nullptr）

#include "lc.h"

// Definition for binary tree with next pointer.
struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr)
            return;
        if (root->left != nullptr) {
            root->left->next = root->right;
            root->right->next = root->next != nullptr ? root->next->left : nullptr;
            connect(root->right);
            connect(root->left);
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
