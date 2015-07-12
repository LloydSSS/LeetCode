// http://www.lintcode.com/en/problem/count-of-smaller-number-before-itself
// 线段树应用
// TODO:树状数组
#include "lintcode.h"

class Solution {
public:
    class BSTreeNode {
    public:
        int val, count;
        BSTreeNode *left, *right;
        BSTreeNode(int val, int count) {
            this->val = val;
            this->count = count;
            this->left = this->right = nullptr;
        }
    };
   /**
     * @param A: An integer array
     * @return: Count the number of element before this element 'ai' is
     *          smaller than it and return count number array
     */
    vector<int> countOfSmallerNumberII(vector<int> &A) {
        vector<int> ans;
        BSTreeNode *root = nullptr;
        for (int &a : A) {
            if (root == nullptr)
                root = new BSTreeNode(a, 0);
            else
                insert(root, a);
            ans.push_back(query(root, a));
        }
        return ans;
    }

    void insert(BSTreeNode *root, int a) {
        while (root != nullptr) {
            if (a < root->val) {
                root->count++;
                if (root->left == nullptr) {
                    root->left = new BSTreeNode(a, 0);
                    break;
                } else
                    root = root->left;
            } else {
                if (root->right == nullptr) {
                    root->right = new BSTreeNode(a, 0);
                    break;
                } else
                    root = root->right;
            }
        }
    }

    int query(BSTreeNode *root, int a) {
        int count = 0;
        while (root != nullptr) {
            if (a < root->val) {
                root = root->left;
            } else if (a > root->val) {
                count += root->count+1;
                root = root->right;
            } else {
                count += root->count;
                break;
            }
        }
        return count;
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> v = {1,2,7,8,5};
    auto ans = sol.countOfSmallerNumberII(v);
    for (auto a : ans)
        cout << a;
    return 0;
}
