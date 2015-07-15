// http://www.lintcode.com/en/problem/count-of-smaller-number
// 线段树应用
// TODO:树状数组

#include "lc.h"

// Definition of SegmentTreeNode2:
class SegmentTreeNode2 {
public:
    int start, end, count;
    SegmentTreeNode2 *left, *right;
    SegmentTreeNode2(int start, int end, int count) {
        this->start = start;
        this->end = end;
        this->count = count;
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
   /**
     * @param A: An integer array
     * @return: The number of element in the array that
     *          are smaller that the given integer
     */
    vector<int> countOfSmallerNumber(vector<int> &A, vector<int> &queries) {
        vector<int> ans;
        sort(A.begin(), A.end());
        SegmentTreeNode2 *root = build(A, 0, A.size()-1);
        for (int q : queries) {
            ans.push_back(query(root, 0, A.size()-1, A, q));
        }
        return ans;
    }

    SegmentTreeNode2 * build(vector<int> &A, int start, int end) {
        if (start > end) return nullptr;
        SegmentTreeNode2 *root = new SegmentTreeNode2(start, end, 1);
        if (start == end)
            return root;
        int mid = (start+end)/2;
        SegmentTreeNode2 *lson = build(A, start, mid);
        SegmentTreeNode2 *rson = build(A, mid+1, end);
        int lcount = lson != nullptr ? lson->count : 0;
        int rcount = rson != nullptr ? rson->count : 0;
        root->left = lson;
        root->right = rson;
        root->count = lcount + rcount;
        return root;
    }

    int query(SegmentTreeNode2 *root, int start, int end, vector<int> &A, int q) {
        if (root == nullptr || start > root->end || end < root->start)
            return 0;
        if (q <= A[root->start])
            return 0;
        if (q > A[root->end])
            return root->count;

        int lcount = query(root->left, start, end, A, q);
        int rcount = query(root->right, start, end, A, q);
        return lcount + rcount;
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> v = {1,2,3,4,5,6};
    vector<int> vv = {1,2,3,4};
    auto ans = sol.countOfSmallerNumber(v, vv);
    for (auto a : ans)
        cout << a;
    return 0;
}
