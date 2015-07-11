// http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock/
// 水
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
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
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int ans = 0;
        int low = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < low)
                low = prices[i];
            else
                ans = max(ans, prices[i]-low);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
