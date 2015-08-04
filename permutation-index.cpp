// http://www.lintcode.com/en/problem/permutation-index/#
// http://www.geekviewpoint.com/java/numbers/permutation_index
// Time O(n2), Space O(1)
// 对于排列[1 4 2 3 5]，首先变成[1 3 2 4 5]需要3!次，然后变成[1 2 3 4 5]需要3!次
// 对于A[i]统计[i+1, n)中比A[i]小的数的数量，然后乘以[i+1~n)的排列数

#include "lc.h"

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndex(vector<int>& A) {
        long long ans = 1;
        long long base = 1;
        for (int i = A.size()-2; i >= 0; --i) {
            for (int j = A.size()-1; j > i; --j) {
                if (A[i] > A[j]) {
                    ans += base;
                    swap(A[i], A[j]);
                }
            }
            cout << ans << endl;
            base *= A.size()-i;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v = {6,7,3,2,1};
    cout << sol.permutationIndex(v) << endl;
	return 0;
}
