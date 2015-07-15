// http://www.lintcode.com/en/problem/count-1-in-binary/
// n&(n-1)表示会去掉最后一个bit为1的位

#include "lc.h"

class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int cnt = 0;
        while (num) {
            num &= (num-1);
            cnt++;
        }
        return cnt;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
