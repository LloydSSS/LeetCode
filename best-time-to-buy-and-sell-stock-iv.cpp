// http://www.lintcode.com/en/problem/best-time-to-buy-and-sell-stock-iv/
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
// http://www.cnblogs.com/EdwardLiu/p/4008162.html
// k超过n/2就可以使用best-time-to-buy-and-sell-stock-ii的方法
// Time O(kn), Space O(kn)
// a. 类似背包问题 dp[i][j] 表示在0～j之间交易i次以内的最大收益，因此，dp[i][j]＝max(dp[i][j-1], prices[j] - prices[ttt] + dp[i-1][ttt]) ttt表示0～j之间dp[i-1][ttt]-prices[ttt]最大的坐标，因此用一个past_max来纪录即可，不用每次遍历
// Time O(kn), Space O(k)
// b. 初始资金为0，release[i]表示卖出第i次时的最大钱数，hold[i]表示买入第j次的最大钱数，因为hold[i]需要依赖release[i-1]的值，所以需要后序遍历

#include "lc.h"

class Solution {
public:
    /**
     * @param k: An integer
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        return maxProfitOk(k, prices);
        if (prices.size() <= 1 || k == 0) return 0;
        int n = prices.size();
        if (k > n/2) return maxProfitAll(prices);
        vector<vector<int> > dp(k+1, vector<int>(n+1, 0));

        for (int i = 1; i <= k; ++i) {
            int past_max = INT_MIN;
            for (int j = 0; j < n; ++j) {
                dp[i][j+1] = max(dp[i][j], prices[j]+past_max);
                past_max = max(past_max, dp[i-1][j+1]-prices[j]);
            }
        }
        return dp[k][n];
    }

    int maxProfitOk(int k, vector<int> &prices) {
        if (prices.size() <= 1 || k == 0) return 0;
        int n = prices.size();
        if (k > n/2) return maxProfitAll(prices);

        vector<int> release(k+1, 0);
        vector<int> hold(k+1, INT_MIN);

        // i表示在前i天进行交易
        for (int i = 0; i < n; ++i) {
            for (int j = k; j > 0; --j) {
                release[j] = max(release[j], hold[j]+prices[i]);
                hold[j] = max(hold[j], release[j-1]-prices[i]);
            }
        }
        return release[k];
    }

    // global[i][j] = max(global[i-1][j], local[i][j]);
    // 1. sell on day before day i; 2. sell on day i;
    // local[i][j] = max(global[i-1][j-1]+max(diff[i],0), local[i-1][j]+diff[i]);
    // 1. buy and sell on day i; 2. buy on day before day i and sell on day i, combine them in one trans;

    int maxProfit2d(int k, vector<int> &prices) {
        if (prices.size() <= 1 || k == 0) return 0;
        int n = prices.size();
        if (k > n/2) return maxProfitAll(prices);

        vector<vector<int> > global(n, vector<int>(k+1)), local(n, vector<int>(k+1));
        for (int i = 1; i < n; ++i) {
            int diff = prices[i]-prices[i-1];
            for (int j = 1; j <= k; ++j) {
                local[i][j] = max(global[i-1][j-1]+max(diff,0), local[i-1][j]+diff);
                global[i][j] = max(global[i-1][j], local[i][j]);
            }
        }
        return global[n-1][k];
    }

    int maxProfit1d(int k, vector<int> &prices) {
        if (prices.size() <= 1 || k == 0) return 0;
        int n = prices.size();
        if (k > n/2) return maxProfitAll(prices);

        vector<int> global(k+1), local(k+1);
        for (int i = 1; i < n; ++i) {
            int diff = prices[i]-prices[i-1];
            for (int j = k; j >= 1; --j) {
                local[j] = max(global[j-1]+max(diff,0), local[j]+diff);
                global[j] = max(global[j], local[j]);
            }
        }
        return global[k];
    }

    int maxProfitAll(vector<int> &prices) {
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
