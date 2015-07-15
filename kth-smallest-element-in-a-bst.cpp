// https://leetcode.com/problems/summary-ranges/
// 中序遍历，找到第k个

#include "lc.h"

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *p = st.top();
            while (p != NULL) {
                p = p->left;
                st.push(p);
            }
            st.pop();
            if (!st.empty()) {
                p = st.top();
                st.pop();
                if ((--k) == 0)
                    return p->val;
                st.push(p->right);
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    TreeNode *root = new TreeNode(1);
    cout << sol.kthSmallest(root, 1) << endl;
    return 0;
}
