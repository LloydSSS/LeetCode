// http://www.lintcode.com/en/problem/binary-tree-maximum-path-sum/
// 分治，注意负值的处理
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;


// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

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
    int maxPathSumHelper(TreeNode *root) {
        if (root == NULL)
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
