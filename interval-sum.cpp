// http://www.lintcode.com/en/problem/interval-sum/
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

// Definition of Interval:
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

// Definition of SumSegmentTreeNode:
class SumSegmentTreeNode {
public:
    int start, end;
    long long sum;
    SumSegmentTreeNode *left, *right;
    SumSegmentTreeNode(int start, int end, long long sum = 0) {
        this->start = start, this->end = end;
        this->sum = sum;
        this->left = this->right = NULL;
    }
};

class Solution {
public:
    /**
     *@param A, queries: Given an integer array and an query list
     *@return: The result list
     */
    vector<long long> intervalSum(vector<int> &A, vector<Interval> &queries) {
        vector<long long> ans;
        SumSegmentTreeNode *root = build(A, 0, A.size()-1);
        for (int i = 0; i < queries.size(); ++i) {
            ans.push_back(query(root, queries[i].start, queries[i].end));
        }
        return ans;
    }
    /**
     *@param start, end: Denote an segment / interval
     *@return: The root of Segment Tree
     */
    SumSegmentTreeNode * build(vector<int> &A, int start, int end) {
        if (start > end) return nullptr;
        SumSegmentTreeNode *root = new SumSegmentTreeNode(start, end);
        if (start == end) {
            root->sum = A[start];
            return root;
        }
        int mid = (start+end)/2;
        SumSegmentTreeNode *lson = build(A, start, mid);
        SumSegmentTreeNode *rson = build(A, mid+1, end);
        root->left = lson;
        root->right = rson;
        root->sum = lson->sum + rson->sum;
        return root;
    }
    /**
     *@param root, start, end: The root of segment tree and
     *                         an segment / interval
     *@return: The sumimum number in the interval [start, end]
     */
    long long query(SumSegmentTreeNode *root, int start, int end) {
        if (start > root->end || end < root->start)
            return 0;
        if (start <= root->start && end >= root->end)
            return root->sum;
        int mid = (root->start+root->end)/2;
        long long lsum = query(root->left, start, end);
        long long rsum = query(root->right, start, end);
        return lsum + rsum;
    }
    /**
     *@param root, index, value: The root of segment tree and
     *@ change the node's value with [index, index] to the new given value
     *@return: void
     */
    void modify(SumSegmentTreeNode *root, int index, int value) {
        if (index < root->start || index > root->end)
            return;
        if (root->start == root->end) {
            root->sum = value;
        } else {
            modify(root->left, index, value);
            modify(root->right, index, value);
            root->sum = root->left->sum + root->right->sum;
        }
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
