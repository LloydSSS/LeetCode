// http://www.lintcode.com/en/problem/binary-tree-preorder-traversal/
// https://leetcode.com/problems/binary-tree-preorder-traversal/
// Time O(n), Space O(n)
// 迭代版：栈
/*
对root进行异常处理
将root压入栈
循环终止条件为栈s为空，所有元素均已处理完
访问当前栈顶元素(首先取出栈顶元素，随后pop掉栈顶元素)并存入最终结果
将右、左节点分别压入栈内，以便取元素时为先左后右。
返回最终结果
 */

// Time O(n), Space O(1)
// morris
#include "lc.h"

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *p = st.top();
            st.pop();
            ans.push_back(p->val);
            if (p->right != nullptr)
                st.push(p->right);
            if (p->left != nullptr)
                st.push(p->left);
        }
        return ans;
    }
};

class Solution2 {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */

    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        TreeNode *cur, *pre;
        cur = root;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                ans.push_back(cur->val);
                pre = cur; /* cur 刚刚被访问过 */
                cur = cur->right;
            } else {
                /* 查找前驱 */
                TreeNode *node = cur->left;
                while (node->right != nullptr && node->right != cur)
                    node = node->right;

                if (node->right == nullptr) { /* 还没线索化,则建立线索 */
                    ans.push_back(cur->val); /* 仅这一行的位置与中序不同 */
                    node->right = cur;
                    pre = cur; /* cur 刚刚被访问过 */
                    cur = cur->left;
                } else { /* 已经线索化,则删除线索 */
                    node->right = nullptr;
                    /* pre = cur; 不能有这句,cur 已经被访问 */
                    cur = cur->right;
                }
            }

        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
