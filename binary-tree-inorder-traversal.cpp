// http://www.lintcode.com/en/problem/binary-tree-inorder-traversal/
// https://leetcode.com/problems/binary-tree-inorder-traversal/
// Time O(n), Space O(n)
// 迭代版：栈
/*
使用辅助栈改写递归程序，中序遍历没有前序遍历好写，其中之一就在于入栈出栈的顺序和限制规则。我们采用「左根右」的访问顺序可知主要由如下四步构成。

首先需要一直对左子树迭代并将非空节点入栈
节点指针为空后不再入栈
当前节点为空时进行出栈操作，并访问栈顶节点
将当前指针p用其右子节点替代
步骤2,3,4对应「左根右」的遍历结构，只是此时的步骤2取的左值为空。
 */
// Time O(n), Space O(1)
// morris
#include "lc.h"

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        // if (root == nullptr)
        //     return ans;
        TreeNode *p = root;
        stack<TreeNode *> st;
        while (!st.empty() || p != nullptr) {
            if (p != nullptr) {
                st.push(p);
                p = p->left;
            } else {
                p = st.top();
                st.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
        return ans;
    }
};

// Morris 中序遍历,时间复杂度 O(n),空间复杂度 O(1)
class Solution2 {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
    vector<int> inorderTraversal(TreeNode *root) {
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
                    node->right = cur;
                    /* pre = cur; 不能有这句,cur 已经被访问 */
                    cur = cur->left;
                } else { /* 已经线索化,则删除线索 */
                    ans.push_back(cur->val); /* 仅这一行的位置与先序不同 */
                    node->right = nullptr;
                    pre = cur; /* cur 刚刚被访问过 */
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
