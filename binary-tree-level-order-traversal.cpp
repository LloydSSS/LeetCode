// http://www.lintcode.com/problem/binary-tree-level-order-traversal
// bfs
// 纪录高度或者使用两个队列
#include "lintcode.h"

class Solution {
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int> > retv;
        if (root == nullptr) return retv;

        queue<pair<TreeNode *, int> > qu;
        qu.push(make_pair(root, 0));
        while (!qu.empty()) {
            pair<TreeNode *, int> pr = qu.front();
            qu.pop();
            TreeNode *p = pr.first;
            int d = pr.second;
            if (d == retv.size())
                retv.push_back(vector<int>());
            retv[d].push_back(p->val);
            if (p->left)
                qu.push(make_pair(p->left, d+1));
            if (p->right)
                qu.push(make_pair(p->right, d+1));
        }
        return retv;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
