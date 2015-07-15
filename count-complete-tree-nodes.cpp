// https://leetcode.com/problems/count-complete-tree-nodes/
// 如果从某节点一直向左的高度 = 一直向右的高度, 那么以该节点为root的子树一定是complete binary tree. 而 complete binary tree的节点数,可以用公式算出 2^h - 1. 如果高度不相等, 则递归调用 return countNode(left) + countNode(right) + 1.  复杂度为O(h^2)
#include "lc.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int ldepth = 1, rdepth = 1;
        TreeNode *p = root;
        while (p->left != nullptr) {
            ldepth++;
            p = p->left;
        }
        p = root;
        while (p->right != nullptr) {
            rdepth++;
            p = p->right;
        }
        if (ldepth == rdepth)
            return pow(2, ldepth) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
