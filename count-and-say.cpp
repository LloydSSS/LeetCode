// http://www.lintcode.com/en/problem/count-and-say/
// 水
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param n the nth
     * @return the nth sequence
     */
    string countAndSay(int n) {
        string s = "1";
        while (--n) {
            string tmp(s);
            s = "";
            for (int i = 0; i < tmp.size();) {
                char c = tmp[i];
                int len = 1;
                while (len+i < tmp.size() && tmp[i+len] == c)
                    len++;
                s += to_string(len) + c;
                i += len;
            }
        }
        return s;
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
