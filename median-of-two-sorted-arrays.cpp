// http://www.lintcode.com/en/problem/median-of-two-sorted-arrays/
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// a. Time:O(logn) Space:O(1)
/* 假设 A 和 B 的元素个数都大于 k/2,我们将 A 的第 k/2 个元素(即 A[k/2-1])和 B 的第 k/2 个元素(即 B[k/2-1])进行比较,有以下三种情况(为了简化这里先假设 k 为偶数,所得到的结论 对于 k 是奇数也是成立的):
    A[k/2-1] == B[k/2-1] • A[k/2-1] > B[k/2-1] • A[k/2-1] < B[k/2-1]
如果 A[k/2-1] < B[k/2-1],意味着 A[0] 到 A[k/2-1 的肯定在 A ∪ B 的 top k 元素的范围 内,换句话说,A[k/2-1 不可能大于 A ∪ B 的第 k 大元素。留给读者证明。
因此,我们可以放心的删除 A 数组的这 k/2 个元素。同理,当 A[k/2-1] > B[k/2-1] 时,可 以删除 B 数组的 k/2 个元素。
当 A[k/2-1] == B[k/2-1] 时,说明找到了第 k 大的元素,直接返回 A[k/2-1] 或 B[k/2-1] 即可。
  因此,我们可以写一个递归函数。那么函数什么时候应该终止呢?
    当A或B是空时,直接返回B[k-1]或A[k-1];
    当k=1是,返回min(A[0],B[0]);
    当A[k/2-1]==B[k/2-1]时,返回A[k/2-1]或B[k/2-1]
*/

#include "lc.h"

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        int len = A.size()+B.size();
        if (len%2)
            return findkth(A, 0, A.size(), B, 0, B.size(), len/2+1);
        else
            return (findkth(A, 0, A.size(), B, 0, B.size(), len/2) +
                    findkth(A, 0, A.size(), B, 0, B.size(), len/2+1))/2.0;
    }

    int findkth(vector<int> &A, int ia, int lena,
                vector<int> &B, int ib, int lenb,
                int k) {
        if (lena > lenb)
            return findkth(B, ib, lenb, A, ia, lena, k);
        if (lena == 0)
            return B[ib+k-1];
        if (k == 1) return min(A[ia], B[ib]);

        int idx_a = min(k/2, lena), idx_b = k-idx_a;
        if (A[ia+idx_a-1] == B[ib+idx_b-1])
            return A[ia+idx_a-1];
        else if (A[ia+idx_a-1] < B[ib+idx_b-1])
            return findkth(A, ia+idx_a, lena-idx_a, B, ib, lenb, k-idx_a);
        else
            return findkth(A, ia, lena, B, ib+idx_b, lenb-idx_b, k-idx_b);
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> A = {1,2,3,4,5,6};
    vector<int> B = {2,3,4,5};
    cout << sol.findMedianSortedArrays(A, B) << endl;
	return 0;
}
