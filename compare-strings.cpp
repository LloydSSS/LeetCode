// http://www.lintcode.com/en/problem/compare-strings/
// 使用一个hash table来计数。判断是否A的所有字母计数都大于B

#include "lc.h"

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true
     *           else return false
     */
    bool compareStrings(string A, string B) {
        if (A.size() < B.size()) return false;

        vector<int> ma(26, 0);
        vector<int> mb(26, 0);
        for (int i = 0; i < A.size(); ++i) {
            ma[A[i]-'A']++;
        }
        for (int i = 0; i < B.size(); ++i) {
            mb[B[i]-'A']++;
        }

        for (int i = 0; i < 26; ++i) {
            if (ma[i] < mb[i]) return false;
        }
        return true;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
