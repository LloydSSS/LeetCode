// https://leetcode.com/problems/same-tree/
// 水

#include "lc.h"

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
