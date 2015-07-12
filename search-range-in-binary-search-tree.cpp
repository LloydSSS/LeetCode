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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        vector<int> retv;
        if (root == nullptr) return retv;

        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            while (st.top()->left != nullptr) {
                st.push(st.top()->left);
            }
            TreeNode *p = st.top();
            if (p->val >= k1 && p->val <= k2)
                retv.push_back(p->val);
            if (p->val > k2)
                break;
            st.pop();
            if (p->right)
                st.push(p->right);
        }
        return retv;
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    sol.searchRange(root, 0, 4);
    return 0;
}
