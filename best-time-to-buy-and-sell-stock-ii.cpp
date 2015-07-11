// http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock-ii/
// Time:O(n), Space O(1)
// 不限制交易次数，计算每一天价格和前一天价格的差，累加整数

#include "lintcode.h"

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int ans = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i]-prices[i-1] > 0)
                ans += prices[i]-prices[i-1];
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
