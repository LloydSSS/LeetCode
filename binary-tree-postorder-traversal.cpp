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

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> retv;
        if (root == NULL)
            return retv;
        
        TreeNode *pre = NULL;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            if ((cur->left == NULL && cur->right == NULL) ||
                (pre != NULL && (cur->left == pre || cur->right == pre))) {
                retv.push_back(cur->val);
                pre = cur;
            } else {
                if (cur->right != NULL)
                    st.push(cur->right);
                if (cur->left != NULL)
                    st.push(cur->left);                
            }
        }
        return retv;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
