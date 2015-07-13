// http://www.lintcode.com/en/problem/max-tree/
// a. Time:O(n) Space:O(n) Cartesian Tree：二叉排序树＋堆，左子树的key(index)比根小，右子树的key(index)比根大，左右子树的value比根小。
// 使用单调(减)堆栈
// (1）如果新来一个数，比堆栈顶的树根的数小，则把这个数作为一个单独的节点压入堆栈。
//（2) 否则，不断从堆栈里弹出树，新弹出的树以旧弹出的树为右子树，连接起来，直到目前堆栈顶的树根的数大于新来的数。然后，这个树作为新节点的左子树，把这个新树压入堆栈。
// (3) 最后将堆栈里面的节点连接起来，新节点作为旧节点右子树

#include "lintcode.h"

class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        stack<TreeNode *> st;
        for (int v : A) {
            if (st.empty() || st.top()->val >= v)
                st.push(new TreeNode(v));
            else {
                TreeNode *n1 = st.top();
                st.pop();
                while (!st.empty() && st.top()->val < v) {
                    TreeNode *n2 = st.top();
                    st.pop();
                    n2->right = n1;
                    n1 = n2;
                }
                TreeNode *node = new TreeNode(v);
                node->left = n1;
                st.push(node);
            }
        }
        TreeNode *n1 = st.top();
        st.pop();
        while (!st.empty()) {
            TreeNode *n2 = st.top();
            st.pop();
            n2->right = n1;
            n1 = n2;
        }
        return n1;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v = {2,5,6,0,3,1};
    auto ans = sol.maxTree(v);
	return 0;
}
