// http://www.lintcode.com/en/problem/segment-tree-query/
// 水
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

// Definition of SegmentTreeNode:
class SegmentTreeNode {
public:
    int start, end, max;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int max) {
        this->start = start, this->end = end;
        this->max = max;
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The maximum number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        if (start > root->end || end < root->start)
            return INT_MIN;
        if (start <= root->start && end >= root->end)
            return root->max;
        int mid = (root->start+root->end)/2;
        int lmax = query(root->left, start, end);
        int rmax = query(root->right, start, end);
        return max(lmax, rmax);
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    SegmentTreeNode *root = new SegmentTreeNode(0, 3, 4);
    root->left = new SegmentTreeNode(0, 1, 4);
    root->right = new SegmentTreeNode(2, 3, 3);
    root->left->left = new SegmentTreeNode(0, 0, 1);
    root->left->right = new SegmentTreeNode(1, 1, 4);
    root->right->left = new SegmentTreeNode(2, 2, 2);
    root->right->right = new SegmentTreeNode(3, 3, 3);

    cout << sol.query(root, 0, 0) << endl;
    return 0;
}
