// http://www.lintcode.com/en/problem/permutation-sequence/
// https://leetcode.com/problems/permutation-sequence/
// 康托编码
/*
利用康托编码的思路,假设有n个不重复的元素,第k个排列是a1,a2,a3,...,an,那么a1 是 哪一个位置呢?
我们把 a1 去掉,那么剩下的排列为 a2, a3, ..., an, 共计 n − 1 个元素,n − 1 个元素共有 (n − 1)! 个排列,于是就可以知道 a1 = k/(n − 1)!。
同理,a2,a3,...,an 的值推导如下:
k2= k%(n − 1)!
a2= k2 /(n − 2)!
···
kn−1 = kn−2 %2!
an−1 = kn−1 /1!
an =0
 */

#include "lc.h"

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

class Solution2 {
public:
    string getPermutation(int n, int k) {
        string ans;
        int *fact = new int[n+1];
        bool *used = new bool[n+1];
        memset(used, 0, sizeof(bool) * (n+1));
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = fact[i-1] * (i);
        }
        for (int i = n; i > 0; --i) {
            int v = (k-1) / fact[i-1];
            for (int j = 1; j <= n; ++j) {
                if (!used[j]) {
                    if (v == 0) {
                        used[j] = true;
                        ans += '0' + j;
                        break;
                    } else
                        v--;
                }
            }
            k = k - ((k-1) / fact[i-1])*fact[i-1];
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
