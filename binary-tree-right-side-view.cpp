// https://leetcode.com/problems/binary-tree-right-side-view/
// Time O(n), Space O(n)
// 先序遍历，纪录深度，每个深度第一个出现的值既是right side view
#include "lc.h"

class Solution {
public:
    vector<int> result;
    void preorder(TreeNode* root, int dep) {
        if (root == NULL) return;
        if (dep == result.size())
            result.push_back(root->val);

        preorder(root->right, dep+1);
        preorder(root->left, dep+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        preorder(root, 0);
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
