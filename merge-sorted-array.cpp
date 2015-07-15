// http://www.lintcode.com/en/problem/merge-sorted-array/
// 从后向前merge

#include "lc.h"

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements,
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
        int i = m-1, j = n-1;
        for (int idx = m+n-1; idx >= 0; --idx) {
            if (j < 0 || (i >= 0 && A[i] > B[j])) {
                A[idx] = A[i--];
            } else {
                A[idx] = B[j--];
            }
        }
    }
};



int main(int argc, char const *argv[]) {
	Solution sol;
    int A[5] = {1, 2, 3};
    int B[2] = {4, 5};
    sol.mergeSortedArray(A, 3, B, 2);
    for (int i = 0; i < 5; ++i)
    {
        cout << A[i] << endl;
    }
	return 0;
}
