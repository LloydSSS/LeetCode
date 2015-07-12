#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;


// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        return helper(A, 0, A.size());
    }

    TreeNode *helper(vector<int> &A, int l, int r) {
        if (l == r) return nullptr;
        if (l + 1 == r) return new TreeNode(A[l]);
        int m = (l+r)/2;
        TreeNode *root = new TreeNode (A[m]);
        root->left = helper(A, l, m);
        root->right = helper(A, m+1, r);
        return root;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
