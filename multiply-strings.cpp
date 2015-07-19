// https://leetcode.com/problems/multiply-strings/
// 注意负数，模拟乘法

#include "lc.h"

class Solution {
public:
    int num(char c) {
        return c - '0';
    }
    char num2char(int n) {
        return n + '0';
    }
    string multiply(string num1, string num2) {
        int len = num1.size() + num2.size();
        int *sum = new int[len];
        memset(sum, 0, sizeof(int)*len);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < num1.size(); ++i) {
            for (int j = 0; j < num2.size(); ++j) {
                sum[i+j] += num(num1[i]) * num(num2[j]);
            }
        }
        for (int i = 0; i < len-1; ++i) {
            sum[i+1] += sum[i]/10;
            sum[i] %= 10;
        }
        string sum_str;
        for (int i = len - 1; i >= 0; --i) {
            if (sum_str.size() == 0 && i != 0 && sum[i] == 0)
                continue;
            sum_str += num2char(sum[i]);
        }
        return sum_str;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
