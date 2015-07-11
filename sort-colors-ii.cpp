// http://www.lintcode.com/en/problem/sort-colors-ii/
// 桶排序，使用0～k-1作为buckets，使用负数进行计数
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

class Solution{
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        int i = 0;
        while (i < colors.size()) {
            int c = colors[i];
            if (c <= 0) {
                i++;
            } else if (colors[c-1] >= 0) {
                colors[i] = colors[c-1];
                colors[c-1] = -1;
            } else {
                colors[c-1]--;
                colors[i] = 0;
                i++;
            }
        }
        i = k-1;
        for (int j = colors.size()-1; j >= 0; --j) {
            if (colors[i] < 0) {
                colors[i]++;
                colors[j] = i+1;
            } else {
                i--;
                j++;
            }
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
