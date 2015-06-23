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
     * @return: Inorder in vector which contains node values.
     */
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> retv;
        if (root == NULL)
            return retv;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *p = st.top();
            while (p != NULL) {
                p = p->left;
                st.push(p->left);
            }
            st.pop();
            if (!st.empty()) {
                p = st.top();
                st.pop();
                retv.push_back(p->val);
                st.push(p->right);
            }
        }
        return retv;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    std::vector<int> v = sol.inorderTraversal(root);
    for (int i = 0; i < v.size(); ++i)
        cout << v[i];
    return 0;
}
