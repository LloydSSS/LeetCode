// https://leetcode.com/problems/sum-root-to-leaf-numbers/
// dfs遍历到叶子节点则加和

#include "lc.h"

class Solution {
private:
    int sum;
public:
    void dfs(TreeNode *root, int num) {
        if (root == NULL)
            return;
        num = num*10 + root->val;
        if (root->left == NULL && root->right == NULL) {
            sum += num;
        }
        dfs(root->left, num);
        dfs(root->right, num);
    }
    int sumNumbers(TreeNode *root) {
        sum = 0;
        dfs(root, 0);
        return sum;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
