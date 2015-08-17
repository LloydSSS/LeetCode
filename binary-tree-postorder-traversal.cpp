// http://www.lintcode.com/en/problem/binary-tree-postorder-traversal/
// https://leetcode.com/problems/binary-tree-postorder-traversal/
// Time O(n), Space O(n)
// 迭代版：栈
/*
遍历顺序为『左右根』，判断根节点是否应该从栈中剔除有两种条件，一为无子节点，二为子节点已遍历过。判断子节点是否遍历过需要排除pre == nullptr 的情况，因为 pre 初始化为 nullptr.

将递归写成迭代的难点在于如何在迭代中体现递归本质及边界条件的确立，可使用简单示例和纸上画出栈调用图辅助分析。
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

    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;

        TreeNode *pre = nullptr;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            // 孩子已经遍历过了
            if ((cur->left == nullptr && cur->right == nullptr) ||
                (pre != nullptr && (cur->left == pre || cur->right == pre))) {
                ans.push_back(cur->val);
                st.pop();
                pre = cur;
            } else {
                if (cur->right != nullptr)
                    st.push(cur->right);
                if (cur->left != nullptr)
                    st.push(cur->left);
            }
        }
        return ans;
    }
};

// Morris 后序遍历,时间复杂度 O(n),空间复杂度 O(1)
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        TreeNode dummy(-1);
        TreeNode *cur, *prev = nullptr;
        std::function < void(const TreeNode*)> visit =
            [&result](const TreeNode *node){
            result.push_back(node->val);
        };
        dummy.left = root;
        cur = &dummy;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                prev = cur; /* 必须要有 */
                cur = cur->right;
            } else {
                TreeNode *node = cur->left;
                while (node->right != nullptr && node->right != cur) {}
                    node = node->right;

                if (node->right == nullptr) { /* 还没线索化,则建立线索 */
                    node->right = cur;
                    prev = cur; /* 必须要有 */
                    cur = cur->left;
                } else {/*已经线索化,则访问节点,并删除线索 */
                    visit_reverse(cur->left, prev, visit);
                    prev->right = nullptr;
                    prev = cur; /* 必须要有 */
                    cur = cur->right;
                }
            }
        }
        return result;
    }

private:
// 逆转路径
    static void reverse(TreeNode *from, TreeNode *to) {
        TreeNode *x = from, *y = from->right, *z;
        if (from == to) return;
        while (x != to) {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
        }
}
// 访问逆转后的路径上的所有结点
    static void visit_reverse(TreeNode* from, TreeNode *to,
                        std::function< void(const TreeNode*) >& visit) {
        TreeNode *p = to;
        reverse(from, to);
        while (true) {
            visit(p);
            if (p == from)
                break;
            p = p->right;
        }
        reverse(to, from);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
