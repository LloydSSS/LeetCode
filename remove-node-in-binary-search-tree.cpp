// http://www.lintcode.com/en/problem/remove-node-in-binary-search-tree/
// 设置一个伪根，删除节点为根节点时不用特殊处理，递归调用removeNodeHelper，当发现匹配的值时，如果左右子树有一个为空，则直接把另一个子树提升上来；否则，把右子树上移，左子树作为右子树的左子树，右子树原先的左子树放在原先左子树的右子树的最右边

#include "lintcode.h"

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        if (root == nullptr)
            return root;
        TreeNode *dummy_root = nullptr;
        if (value == INT_MIN) {
            dummy_root = new TreeNode(value+1);
            dummy_root->left = root;
            return removeNodeHelper(dummy_root, value)->left;
        } else {
            dummy_root = new TreeNode(value-1);
            dummy_root->right = root;
            return removeNodeHelper(dummy_root, value)->right;
        }
    }

    TreeNode* removeNodeHelper(TreeNode* root, int value) {
        if (root == nullptr)
            return root;
        if (value < root->val)
            root->left = removeNodeHelper(root->left, value);
        else if (value > root->val)
            root->right = removeNodeHelper(root->right, value);
        else {
            TreeNode *tmp = root;
            if (root->left == nullptr)
                root = root->right;
            else if (root->right == nullptr)
                root = root->left;
            else {
                TreeNode *ln = root->left;
                TreeNode *rn = root->right;
                TreeNode *rln = root->right->left;
                TreeNode *lrn = root->left;
                while (lrn->right != nullptr) {
                    lrn = lrn->right;
                }
                root = rn;
                root->left = ln;
                lrn->right = rln;
            }
            delete tmp;
        }
        return root;
    }
};
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
