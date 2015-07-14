// http://www.lintcode.com/en/problem/validate-binary-search-tree/
// 中序遍历，保留前一个遍历元素的值，与当前值进行比较，应该小于当前值

#include "lintcode.h"

class Solution {
public:
    bool inorder(TreeNode *root, long long &last_val) {
        if (root->left != nullptr && !inorder(root->left, last_val))
            return false;
        if (last_val >= root->val)
            return false;
        last_val = root->val;
        if (root->right != nullptr && !inorder(root->right, last_val))
            return false;
        return true;

    }
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return true;
        long long last_val = LONG_MIN;
        return inorder(root, last_val);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
