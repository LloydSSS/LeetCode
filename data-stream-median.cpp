// http://www.lintcode.com/en/problem/data-stream-median/
// 用一个最小堆来维护较大部分的数、用一个最大堆来维护较小部分的数，保持最大堆的size要大于最小堆的size，最大堆的堆顶即是中位数
#include "lintcode.h"

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        priority_queue<int, vector<int>, greater<int> > higherq;
        priority_queue<int> lowerq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (lowerq.empty())
                lowerq.push(nums[i]);
            else if (nums[i] <= lowerq.top()) {
                if (lowerq.size() > higherq.size()) {
                    higherq.push(lowerq.top());
                    lowerq.pop();
                }
                lowerq.push(nums[i]);
            } else {
                higherq.push(nums[i]);
                if (lowerq.size() < higherq.size()) {
                    lowerq.push(higherq.top());
                    higherq.pop();
                }
            }
            ans.push_back(lowerq.top());
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
