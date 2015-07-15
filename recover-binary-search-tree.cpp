// https://leetcode.com/problems/recover-binary-search-tree/
// 先找到两个节点，然后交换

#include "lc.h"

class Solution {
public:
    TreeNode *s1, *s2;
    void check(TreeNode *root, TreeNode *&last) {
        if (root == NULL) return;
        check(root->left, last);
        if (last != NULL && last->val >= root->val) {
            if (s1 == NULL) {
                s1 = last;
                s2 = root;
            } else {
                s2 = root;
                return;
            }
        }
        last = root;
        check(root->right, last);
    }
    void recoverTree(TreeNode *root) {
        s1 = NULL;
        s2 = NULL;
        TreeNode *last = NULL;
        check(root, last);
        s1->val ^= s2->val;
        s2->val ^= s1->val;
        s1->val ^= s2->val;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
