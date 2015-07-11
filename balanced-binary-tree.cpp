// http://www.lintcode.com/en/problem/balanced-binary-tree/
// Time:O(n)
// 在递归计算节点高度的同时判断二叉树是否平衡，避免重复计算

#include "lintcode.h"

class Solution {
public:
    bool ans;
    int getDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int left_depth = getDepth(root->left);
        int right_depth = getDepth(root->right);
        if (abs(left_depth - right_depth) > 1)
            ans = false;
        return left_depth > right_depth ? left_depth+1 : right_depth+1;
    }
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        ans = true;
        getDepth(root);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
