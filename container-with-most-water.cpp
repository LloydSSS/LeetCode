// http://www.lintcode.com/en/problem/container-with-most-water/
// 分治，注意负值的处理
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
     * @param heights: a vector of integers
     * @return: an integer
     */
    int maxArea(vector<int> &heights) {
        int left = 0;
        int right = heights.size()-1;
        int ans = 0;
        while (left < right) {
            ans = max(ans, min(heights[left], heights[right]) * (right-left));
            if (heights[left] < heights[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> v = {1,1};
    cout << sol.maxArea(v) << endl;
    return 0;
}
