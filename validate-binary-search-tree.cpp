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
    bool inorder(TreeNode *root, long long &last_val) {

        if (root->left != NULL && !inorder(root->left, last_val))
            return false;
        if (last_val >= root->val)
            return false;
        last_val = root->val;
        if (root->right != NULL && !inorder(root->right, last_val))
            return false;
        return true;

    }
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if (root == NULL)
            return true;
        long long last_val = LONG_MIN;
        return inorder(root, last_val);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
