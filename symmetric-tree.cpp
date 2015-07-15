// https://leetcode.com/problems/symmetric-tree/
// 递归判断

#include "lc.h"

class Solution {
public:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (left == NULL && right == NULL)
            return true;
        if (left != NULL && right != NULL) {
            if (left->val != right->val)
                return false;
        } else
            return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root) {
        return isSymmetric(root, root);
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
