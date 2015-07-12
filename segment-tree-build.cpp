// http://www.lintcode.com/en/problem/segment-tree-build/
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
    int start, end;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end) {
        this->start = start, this->end = end;
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SegmentTreeNode * build(int start, int end) {
        if (start > end) return nullptr;
        SegmentTreeNode *root = new SegmentTreeNode(start, end);
        if (start == end)
            return root;
        int mid = (start+end)/2;
        SegmentTreeNode *lson = build(start, mid);
        SegmentTreeNode *rson = build(mid+1, end);
        root->left = lson;
        root->right = rson;
        return root;
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
