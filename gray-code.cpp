// http://www.lintcode.com/en/problem/gray-code/
/*
自然二进制码转换为格雷码:g0 = b0 , gi = bi ⊕ bi−1 保留自然二进制码的最高位作为格雷码的最高位,格雷码次高位为二进制码的高位与次高位异
或,其余各位与次高位的求法类似。例如,将自然二进制码 1001,转换为格雷码的过程是:保留最 高位;然后将第 1 位的 1 和第 2 位的 0 异或,得到 1,作为格雷码的第 2 位;将第 2 位的 0 和第 3 位 的 0 异或,得到 0,作为格雷码的第 3 位;将第 3 位的 0 和第 4 位的 1 异或,得到 1,作为格雷码的 第 4 位,最终,格雷码为 1101。
格雷码转换为自然二进制码:b0 = g0 , bi = gi ⊕ bi−1
保留格雷码的最高位作为自然二进制码的最高位,次高位为自然二进制高位与格雷码次高位异 或,其余各位与次高位的求法类似。例如,将格雷码 1000 转换为自然二进制码的过程是:保留最高 位 1,作为自然二进制码的最高位;然后将自然二进制码的第 1 位 1 和格雷码的第 2 位 0 异或,得 到 1,作为自然二进制码的第 2 位;将自然二进制码的第 2 位 1 和格雷码的第 3 位 0 异或,得到 1, 作为自然二进制码的第 3 位;将自然二进制码的第 3 位 1 和格雷码的第 4 位 0 异或,得到 1,作为 自然二进制码的第 4 位,最终,自然二进制码为 1111。
格雷码有数学公式,整数 n 的格雷码是 n ⊕ (n/2)。
这题要求生成 n 比特的所有格雷码。
方法 1,最简单的方法,利用数学公式,对从 0 ∼ 2n − 1 的所有整数,转化为格雷码。
方法 2,n 比特的格雷码,可以递归地从 n − 1 比特的格雷码生成。

 */

#include "lintcode.h"

class Solution {
public:
    /**
     * @param n a number
     * @return Gray code
     */
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 0; i < n; ++i) {
            for (int j = (1<<i)-1; j >= 0; --j) {
                int code = ans[j] ^ (1<<i);
                ans.push_back(code);
            }
        }
        return ans;
    }
};

// LeetCode, Gray Code
// 数学公式,时间复杂度 O(2^n),空间复杂度 O(1)
class Solution2 {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        const size_t size = 1 << n;  // 2^n
        result.reserve(size);
        for (size_t i = 0; i < size; ++i)
            result.push_back(binary_to_gray(i));
        return result;
        }
private:
    unsigned int binary_to_gray(unsigned int n) {
        return n ^ (n >> 1);
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
