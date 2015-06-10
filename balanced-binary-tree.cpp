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
    bool ans;
    int getDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int left_depth = getDepth(root->left);
        int right_depth = getDepth(root->right);
        if (abs(left_depth - right_depth) > 1)
            ans = false;
        return left_depth > right_depth ? left_depth+1 : right_depth+1;
    }
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        if (root == NULL)
            return true;
        ans = true;
        getDepth(root);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
