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
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) return;
        TreeNode *pn = root->left;
        root->left = root->right;
        root->right = pn;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
