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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if (root == NULL)
            return root;
        TreeNode *dummy_root = NULL;
        if (value == INT_MIN) {
            dummy_root = new TreeNode(value+1);
            dummy_root->left = root;
            return removeNodeHelper(dummy_root, value)->left;
        } else {
            dummy_root = new TreeNode(value-1);
            dummy_root->right = root;
            return removeNodeHelper(dummy_root, value)->right;
        }
    }

    TreeNode* removeNodeHelper(TreeNode* root, int value) {
        if (root == NULL)
            return root;
        if (value < root->val)
            root->left = removeNodeHelper(root->left, value);
        else if (value > root->val)
            root->right = removeNodeHelper(root->right, value);
        else {
            TreeNode *tmp = root;
            if (root->left == NULL)
                root = root->right;
            else if (root->right == NULL)
                root = root->left;
            else {
                TreeNode *ln = root->left;
                TreeNode *rn = root->right;
                TreeNode *rln = root->right->left;
                TreeNode *lrn = root->left;
                while (lrn->right != NULL) {
                    lrn = lrn->right;
                }
                root = rn;
                root->left = ln;
                lrn->right = rln;
            }
            delete tmp;
        }
        return root;
    }
};
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
