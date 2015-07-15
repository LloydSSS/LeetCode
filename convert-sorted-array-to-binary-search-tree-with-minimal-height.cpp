// http://www.lintcode.com/en/problem/convert-sorted-array-to-binary-search-tree-with-minimal-height/
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// 分治，找到中心位置，然后递归调用

#include "lc.h"

class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        return helper(A, 0, A.size());
    }

    TreeNode *helper(vector<int> &A, int l, int r) {
        if (l == r) return nullptr;
        if (l + 1 == r) return new TreeNode(A[l]);
        int m = (l+r)/2;
        TreeNode *root = new TreeNode (A[m]);
        root->left = helper(A, l, m);
        root->right = helper(A, m+1, r);
        return root;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
