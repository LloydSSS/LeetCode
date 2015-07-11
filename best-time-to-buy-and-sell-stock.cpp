// http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock/
// Time:O(n), Space O(1)
// 只交易一次：纪录最低价格，以及当前价格和最低价格的差的最大值

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
