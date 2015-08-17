// http://www.lintcode.com/en/problem/unique-binary-search-trees-ii/
// https://leetcode.com/problems/unique-binary-search-trees-ii/
// dfs, 对于1~n的二叉树，先确定根节点，然后获得所有的子树，之后组成二叉树

#include "lc.h"

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        return dfs(1, n);
    }
    vector<TreeNode *> dfs(int left, int right) {
        vector<TreeNode *> ans;
        if (left > right) {
            ans.push_back(nullptr);
            return ans;
        }
        for (int i = left; i <= right; ++i) {
            vector<TreeNode *> lsons = dfs(left, i-1);
            vector<TreeNode *> rsons = dfs(i+1, right);
            for (auto l : lsons) {
                for (auto r : rsons) {
                    TreeNode *root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
