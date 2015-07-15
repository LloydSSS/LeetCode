// http://www.lintcode.com/en/problem/continuous-subarray-sum/
// dp, 纪录开始下标
// 空间复杂度可以做到O(1)，只纪录当前的最大和

#include "lc.h"

class Solution {
public:
    /**
     * @param A an integer array
     * @return  A list of integers includes the index of
     *          the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int>& A) {
        vector<int> ans(2);
        if (A.size() == 0)
            return ans;
        vector<int> dp(A.size());
        vector<int> from(A.size());
        dp[0] = A[0];
        int max_sum = dp[0];
        for (int i = 1; i < A.size(); ++i) {
            if (dp[i-1] > 0) {
                dp[i] = dp[i-1]+A[i];
                from[i] = from[i-1];
            } else {
                dp[i] = A[i];
                from[i] = i;
            }
            if (dp[i] > max_sum) {
                max_sum = dp[i];
                ans[0] = from[i];
                ans[1] = i;
            }
        }
        return ans;
    }

    int findMaxSubarray(const vector<int>& A, vector<int> &max_i_j) {
        int curr_sum = A[0];
        int max_sum = curr_sum;
        for (int i = 0, j = 1; j < A.size(); ++j) {
            if (curr_sum < 0) {
                i = j;
                curr_sum = 0;
            }

            curr_sum += A[j];
            if (curr_sum > max_sum) {
                max_sum = curr_sum;
                max_i_j[0] = i, max_i_j[1] = j;
            }
        }

        return max_sum;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
