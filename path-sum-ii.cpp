// https://leetcode.com/problems/path-sum-ii/
// 递归版

#include "lc.h"

class Solution {
public:
    vector<vector<int> > ans;
    void travel(TreeNode *root, int sum, vector<int> path) {
        if (root == NULL)
            return;
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (root->val == sum) {
                ans.push_back(path);
                return;
            } else
                return;
        }
        travel(root->left, sum - root->val, path);
        travel(root->right, sum - root->val, path);
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        travel(root, sum, path);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
