// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// 一般二叉树
// 对于每个节点
// 如果它没有孩子，直接返回
// 如果有两个孩子，将左孩子的next指向右孩子
// 将剩下孩子的next指向父亲兄弟的第一个孩子
// 注意要处理右孩子，再处理左孩子否则上一步无法进行

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
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
            return;
        if (root->left != NULL && root->right != NULL)
            root->left->next = root->right;

        TreeLinkNode *root_next = root->next;
        TreeLinkNode *last = root->right != NULL ? root->right : root->left;
        while (root_next != NULL) {
            if (root_next->left != NULL) {
                last->next = root_next->left;
                break;
            }
            if (root_next->right != NULL) {
                last->next = root_next->right;
                break;
            }
            root_next = root_next->next;
        }
        connect(root->right);
        connect(root->left);
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
