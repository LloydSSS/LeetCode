// http://www.lintcode.com/en/problem/segment-tree-query-ii/
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
    int start, end, count;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int count) {
        this->start = start;
        this->end = end;
        this->count = count;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The count number in the interval [start, end]
     */
    int query(SegmentTreeNode *root, int start, int end) {
        if (root == nullptr) return 0;
        if (start > root->end || end < root->start)
            return 0;
        if (start <= root->start && end >= root->end)
            return root->count;
        int mid = (root->start+root->end)/2;
        int lcount = query(root->left, start, end);
        int rcount = query(root->right, start, end);
        return lcount+rcount;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
