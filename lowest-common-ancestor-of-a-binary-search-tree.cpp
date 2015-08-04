// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// a:从根节点开始找到两个节点的路径，然后在路径中找最后一个一样的节点
// b:LCA满足它的值在p,q之间，递归查找

#include "lc.h"

class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        if (root == nullptr || A == nullptr || B == nullptr) return nullptr;
        vector<TreeNode *> la, lb;
        if (!getpath(root, A, la) || !getpath(root, B, lb)) return nullptr;
        TreeNode *ans = nullptr;
        vector<TreeNode *>::const_iterator iter1 = la.begin();
        vector<TreeNode *>::const_iterator iter2 = lb.begin();
        while (iter1 != la.end() && iter2 != lb.end()) {
            if (*iter1 == *iter2)
                ans = *iter1;
            else
                break;
            iter1++;
            iter2++;
        }
        return ans;
    }

    bool getpath(TreeNode *root, TreeNode *t, vector<TreeNode *> &l) {
        l.push_back(root);
        if (root == t) return true;
        if (root->left != nullptr && getpath(root->left, t, l))
            return true;
        if (root->right != nullptr && getpath(root->right, t, l))
            return true;
        l.pop_back();
        return false;
    }
};

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val)
            return lowestCommonAncestor(root, q, p);
        if (p->val <= root->val && root->val <= q->val)
            return root;
        else if (root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
