// http://www.lintcode.com/en/problem/minimum-depth-of-binary-tree/
// https://leetcode.com/problems/minimum-depth-of-binary-tree/
// bfs,需要纪录节点高度或者使用两个队列

#include "lc.h"

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode *, int> > qu;
        qu.push(make_pair(root, 1));
        while (!qu.empty()) {
            pair<TreeNode *, int> pr = qu.front();
            qu.pop();
            TreeNode *p = pr.first;
            int d = pr.second;
            if (p->left == nullptr && p->right == nullptr)
                return d;
            if (p->left)
                qu.push(make_pair(p->left, d+1));
            if (p->right)
                qu.push(make_pair(p->right, d+1));
        }
        return -1;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
