// http://www.lintcode.com/en/problem/segment-tree-build/
// 线段树建立

#include "lc.h"

class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start;
        this->end = end;
        this->max = max;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     *@param A: a list of integer
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(vector<int>& A) {
        if (A.size() == 0) return nullptr;
        return build(A, 0, A.size()-1);
    }

    SegmentTreeNode *build(vector<int> &A, int start, int end) {
        SegmentTreeNode *root = new SegmentTreeNode(start, end, A[start]);
        if (start != end) {
            int mid = (start+end)/2;
            root->left = build(A, start, mid);
            root->right = build(A, mid+1, end);
            root->max = max(root->left->max, root->right->max);
        }
        return root;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    std::vector<int> v = {3, 2, 1, 4};
    SegmentTreeNode *root = sol.build(v);
    return 0;
}
