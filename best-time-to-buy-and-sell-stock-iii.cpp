// http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock-iii/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
// Time:O(n), Space O(1)
// 两次交易：双向遍历,用两个数组分别纪录前向及后向的最大收益，然后在遍历一遍寻找两者和的最大值
// Time:O(n), Space O(1)
// 初始资金为0，release[i]表示卖出第i次时的最大钱数，hold[i]表示买入第j次的最大钱数，因为hold[i]需要依赖release[i-1]的值，所以需要后序遍历
#include "lc.h"

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1) return 0;
        int ans = 0;
        vector<int> dp(prices.size());
        int low = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < low)
                low = prices[i];
            dp[i] = max(dp[i-1], prices[i]-low);
        }

        vector<int> dp2(prices.size());
        int high = prices[prices.size()-1];
        for (int i = prices.size()-2; i >= 0; --i) {
            if (prices[i] > high)
                high = prices[i];
            dp2[i] = max(dp2[i+1],high-prices[i]);
        }

        for (int i = 0; i < prices.size(); ++i)
            ans = max(ans, dp[i]+dp2[i]);
        return ans;
    }

    // k == 2
    int maxProfitOk(int k, vector<int> &prices) {
        if (prices.size() <= 1 || k == 0) return 0;
        int n = prices.size();
        //if (k > n/2) return maxProfitAll(prices);

        vector<int> release(k+1, 0);
        vector<int> hold(k+1, INT_MIN);

        for (int i = 0; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                release[j] = max(release[j], hold[j]+prices[i]);
                hold[j] = max(hold[j], release[j-1]-prices[i]);
            }
        }
        return release[k];
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
