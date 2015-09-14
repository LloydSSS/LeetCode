// https://leetcode.com/problems/binary-tree-paths/
// dfs

#include "lc.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string vec2str(const vector<int> &path) {
        string retv;
        if (path.size() == 0)
            return retv;
        stringstream ss;
        ss << path[0];
        for (int i = 1; i < path.size(); ++i)
            ss << "->" << path[i];
        ss >> retv;
        return retv;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr) return ans;

        vector<int> path;
        dfs(root, ans, path);
        return ans;
    }

    void dfs(TreeNode *root, vector<string> &ans, vector<int> &path) {
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(vec2str(path));
        }
        if (root->left != nullptr) {
            dfs(root->left, ans, path);
        }
        if (root->right != nullptr) {
            dfs(root->right, ans, path);
        }
        path.pop_back();
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
