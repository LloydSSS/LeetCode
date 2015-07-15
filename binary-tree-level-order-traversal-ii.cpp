// http://www.lintcode.com/problem/binary-tree-level-order-traversal-ii
// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
// bfs
// 纪录高度或者使用两个队列，在i的基础上reverse一下
#include "lc.h"

class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int> > ans;
        if (root == nullptr) return ans;

        queue<pair<TreeNode *, int> > qu;
        qu.push(make_pair(root, 0));
        while (!qu.empty()) {
            pair<TreeNode *, int> pr = qu.front();
            qu.pop();
            TreeNode *p = pr.first;
            int d = pr.second;
            if (d == ans.size())
                ans.push_back(vector<int>());
                ans[d].push_back(p->val);
            if (p->left)
                qu.push(make_pair(p->left, d+1));
            if (p->right)
                qu.push(make_pair(p->right, d+1));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
