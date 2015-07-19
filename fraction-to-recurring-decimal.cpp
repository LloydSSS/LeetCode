// https://leetcode.com/problems/fraction-to-recurring-decimal/
/*
    0.16
6 ) 1.00
    0
    1 0       <-- Remainder=1, mark 1 as seen at position=0.
    - 6
      40      <-- Remainder=4, mark 4 as seen at position=1.
    - 36
       4      <-- Remainder=4 was seen before at position=1, so the fractional part which is 16 starts repeating at position=1 => 1(6).

The key insight here is to notice that once the remainder starts repeating, so does the divided result.

You will need a hash table that maps from the remainder to its position of the fractional part. Once you found a repeating remainder, you may enclose the reoccurring fractional part with parentheses by consulting the position from the table.

The remainder could be zero while doing the division. That means there is no repeating fractional part and you should stop right away.

Just like the question Divide Two Integers, be wary of edge case such as negative fractions and nasty extreme case such as -2147483648 / -1.
*/

#include "lc.h"

class Solution {
public:

    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) return "";

        string res;
        long long n = numerator;
        long long d = denominator;
        if (n > 0 ^ d > 0) res += "-";
        n = abs(n);
        d = abs(d);
        res += to_string(n/d);
        long long r = n%d;
        if (r == 0) return res;
        else res += ".";

        unordered_map<int, int> mp;
        while (r) {
            if (mp.find(r) != mp.end()) {
                res.insert(mp[r], "(");
                res += ")";
                break;
            }
            mp[r] = res.size();
            r *= 10;
            res += to_string(r/d);
            r %= d;
        }

        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
