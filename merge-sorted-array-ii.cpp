// http://www.lintcode.com/en/problem/merge-sorted-array-ii/
// 从前向后比较

#include "lc.h"

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
        vector<int> retv;
        int ia = 0, ib = 0;
        while (ia < A.size() || ib < B.size()) {
            if (ib == B.size() || (ia < A.size() && A[ia] <= B[ib]))
                retv.push_back(A[ia++]);
            else if (ia == A.size() || (ib < B.size() && A[ia] >= B[ib]))
                retv.push_back(B[ib++]);
        }
        return retv;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> A = {1, 2, 3};
    vector<int> B = {4, 5};
    A = sol.mergeSortedArray(A, B);
    for (int i = 0; i < 5; ++i)
    {
        cout << A[i] << endl;
    }
	return 0;
}
