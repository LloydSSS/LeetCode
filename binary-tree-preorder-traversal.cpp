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
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> retv;
        if (root == NULL)
            return retv;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *p = st.top();
            st.pop();
            retv.push_back(p->val);
            if (p->right != NULL)
                st.push(p->right);
            if (p->left != NULL)
                st.push(p->left);
        }
        return retv;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
