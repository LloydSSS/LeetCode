// http://www.lintcode.com/en/problem/insert-node-in-a-binary-search-tree/
// bst查找

#include "lc.h"

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (root == nullptr)
            return node;
        TreeNode *p = root;
        while (true) {
            if (p->val == node->val)
                break;
            if (p->val > node->val) {
                if (p->left == nullptr) {
                    p->left = node;
                    break;
                }
                p = p->left;
            }
            if (p->val < node->val) {
                if (p->right == nullptr) {
                    p->right = node;
                    break;
                }
                p = p->right;
            }
        }
        return root;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
