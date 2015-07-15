// http://www.lintcode.com/en/problem/binary-tree-maximum-path-sum/
// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// 分治，注意负值的处理
// maxPathSumHelper返回以root为起点向下的最长路径和,则通过root的最大路径和为以两个孩子为起点的最大路径和的加和（负数不进行求和）

#include "lc.h"

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        ans = INT_MIN;
        maxPathSumHelper(root);
        return ans;
    }

    int ans;
    // 返回以root为起点向下的最长路径和
    int maxPathSumHelper(TreeNode *root) {
        if (root == nullptr)
            return 0;
        int lsum = maxPathSumHelper(root->left);
        int rsum = maxPathSumHelper(root->right);
        int maxlen = root->val;
        if (lsum > 0) maxlen += lsum;
        if (rsum > 0) maxlen += rsum;
        ans = max(ans, maxlen);
        int retv = root->val;
        if (max(lsum, rsum) > 0)
            retv += max(lsum, rsum);
        return retv;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
