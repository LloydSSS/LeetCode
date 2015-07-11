// http://www.lintcode.com/zh-cn/problem/candy/
// O(n), O(n)   a.从前向后遍历，只考虑每个人左侧的情况，如果rating比前一个要高则，得到的糖果数要比前一个人多1，否则从1开始；然后再从后往前遍历，同样的策略，取两者之间的最大值
// O(n), O(1)   b.如果是递增序列则，给每个人的糖果依次加1，纪录最高值及总数；如果遇见相同rating，则糖果数从1开始记，最高值变成1；如果遇见递减序列，则纪录递减序列的长度，总数每次加上序列的长度，如果序列的长度大于之前的最高值，则最高值要+1，总数也要加1
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
     * @param ratings Children's ratings
     * @return the minimum candies you must give
     */
    int candy(vector<int>& ratings) {
        return candy1pass(ratings);
        if (ratings.size() == 0) return 0;
        int ans = 0;
        vector<int> num(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) num[i] = num[i-1]+1;
        }
        for (int i = ratings.size()-2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) num[i] = max(num[i+1]+1, num[i]);
        }
        for (int i = 0; i < ratings.size(); ++i)
            ans += num[i];
        return ans;
    }

    int candy1pass(vector<int> &ratings) {
        if (ratings.size() == 0) return 0;
        int ans = 1, num = 1;
        int desc_len = 0, top = 1;
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i-1]) {
                num += 1;
                ans += num;
                desc_len = 0;
                top = num;
            } else if (ratings[i] == ratings[i-1]) {
                num = 1;
                ans += num;
                desc_len = 0;
                top = num;
            } else {
                desc_len += 1;
                if (top <= desc_len) {
                    top += 1;
                    ans += 1;
                }
                ans += desc_len;
                num = 1;
            }
        }
        return ans;
    }
};



int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
