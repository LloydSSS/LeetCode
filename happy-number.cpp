// https://leetcode.com/problems/happy-number/
// 如果出现之前出现过的数，则不是，否则一致试下去
/*
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 */

#include "lc.h"

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (n!=1) {
            if (st.find(n) != st.end())
                return false;
            st.insert(n);
            int t = 0;
            while (n) {
                t += (n%10)*(n%10);
                n /= 10;
            }
            n = t;
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
