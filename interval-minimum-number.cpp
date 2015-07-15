// http://www.lintcode.com/en/problem/segment-tree-build/
// 线段树应用

#include "lc.h"

// Definition of MinSegmentTreeNode:
class MinSegmentTreeNode {
public:
    int start, end, min;
    MinSegmentTreeNode *left, *right;
    MinSegmentTreeNode(int start, int end, int min = 0) {
        this->start = start, this->end = end;
        this->min = min;
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries) {
        vector<int> ans;
        MinSegmentTreeNode *root = build(A, 0, A.size()-1);
        for (int i = 0; i < queries.size(); ++i) {
            ans.push_back(query(root, queries[i].start, queries[i].end));
        }
        return ans;
    }
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    MinSegmentTreeNode * build(vector<int> &A, int start, int end) {
        if (start > end) return nullptr;
        MinSegmentTreeNode *root = new MinSegmentTreeNode(start, end);
        if (start == end) {
            root->min = A[start];
            return root;
        }
        int mid = (start+end)/2;
        MinSegmentTreeNode *lson = build(A, start, mid);
        MinSegmentTreeNode *rson = build(A, mid+1, end);
        root->left = lson;
        root->right = rson;
        root->min = min(lson->min, rson->min);
        return root;
    }
    /**
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The minimum number in the interval [start, end]
     */
    int query(MinSegmentTreeNode *root, int start, int end) {
        if (start > root->end || end < root->start)
            return INT_MIN;
        if (start <= root->start && end >= root->end)
            return root->min;
        int mid = (root->start+root->end)/2;
        int lmin = query(root->left, start, end);
        int rmin = query(root->right, start, end);
        return min(lmin, rmin);
    }
    /**
     *@param root, index, value: The root of segment tree and
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(MinSegmentTreeNode *root, int index, int value) {
        if (index < root->start || index > root->end)
            return;
        if (root->start == root->end) {
            root->min = value;
        } else {
            modify(root->left, index, value);
            modify(root->right, index, value);
            root->min = min(root->left->min, root->right->min);
        }
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
