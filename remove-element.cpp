// http://www.lintcode.com/en/problem/remove-element/
// https://leetcode.com/problems/remove-element/
// 元素前移

#include "lc.h"

class Solution {
public:
    /**
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        int idx = 0;
        for (int i = 0; i< A.size(); ++i) {
            if (A[i] != elem)
                A[idx++] = A[i];
        }
        A.erase(A.begin()+idx, A.end());
        return idx;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
