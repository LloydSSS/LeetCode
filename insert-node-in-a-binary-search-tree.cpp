#include <iostream>
#include <algorithm>
#include <vector>
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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (root == NULL)
            return node;
        TreeNode *p = root;
        while (true) {
            if (p->val == node->val)
                break;
            if (p->val > node->val) {
                if (p->left == NULL) {
                    p->left = node;
                    break;
                }
                p = p->left;
            }
            if (p->val < node->val) {
                if (p->right == NULL) {
                    p->right = node;
                    break;
                }
                p = p->right;
            }
        }
        return root;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
