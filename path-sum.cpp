// https://leetcode.com/problems/path-sum/
// 递归版

#include "lc.h"

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum)
                return true;
            else
                return false;
        }
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
