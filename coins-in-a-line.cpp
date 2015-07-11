// http://www.lintcode.com/zh-cn/problem/coins-in-a-line/
// 110110110110...如果n前两个状态为11则，n为0，否则n为1，1代表先手必胜
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param n: an integer
     * @return: a boolean which equals to true if the first player will win
     */
     bool firstWillWin(int n) {
        return n%3 != 0;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
