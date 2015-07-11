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
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     *@param root, index, value: The root of segment tree and
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SegmentTreeNode *root, int index, int value) {
        if (index < root->start || index > root->end)
            return;
        if (root->start == root->end) {
            root->max = value;
        } else {
            modify(root->left, index, value);
            modify(root->right, index, value);
            root->max = max(root->left->max, root->right->max);
        }
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
