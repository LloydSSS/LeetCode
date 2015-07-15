// http://www.lintcode.com/en/problem/maximum-depth-of-binary-tree/

#include "lc.h"

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode *root) {
        if (root == nullptr)
            return 0;
        // if (root->left == nullptr && root->right == nullptr)
        //     return 1;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
