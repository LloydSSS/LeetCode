// http://www.lintcode.com/en/problem/subtree/
// T2是T1的子树，则T1和T2相同，或者T2是T1孩子的子树
// 判断两个节点是否是相同的树

#include "lc.h"

class Solution {
public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL && T2 == NULL) return true;
        if (T1 == NULL) return false;

        if (isSame(T1, T2)) return true;
        return isSubtree(T1->left, T2) || isSubtree(T1->right, T2);
    }

    bool isSame(TreeNode *T1, TreeNode *T2) {
        if (T1 == NULL && T2 == NULL) return true;
        if (T1 == NULL || T2 == NULL) return false;

        if (T1->val == T2->val)
            return isSame(T1->left, T2->left) && isSame(T1->right, T2->right);
        return false;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
