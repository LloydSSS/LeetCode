// http://www.lintcode.com/en/problem/permutation-sequence/
// 用两个链表分别存储，反而简单了

#include "lintcode.h"

class Solution {
public:
    /**
      * @param n: n
      * @param k: the kth permutation
      * @return: return the k-th permutation
      */
    string getPermutation(int n, int k) {
        if (n == 0) return "";
        string s("1"), ans;
        int base = 1;
        for (int i = 1; i < n; ++i) {
            base *= i;
            s += '1'+i;
        }

        k--;
        // 康托编码从0开始
        for (int i = n - 1; i > 0; k %= base, base /= i, --i) {
            auto a = next(s.begin(), k/base);
            ans += *a;
            s.erase(a);
        }
        ans.push_back(s[0]);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
