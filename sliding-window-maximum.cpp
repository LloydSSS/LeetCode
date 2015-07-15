// Sliding Window Maximum
// http://www.lintcode.com/en/problem/sliding-window-maximum/
// a. 优先队列，保存一个窗口的最大值，每次弹出时，同时弹出队首不在窗口内的元素

#include "lc.h"

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> retv;
        if (nums.size() == 0) return retv;
        if (k > nums.size())
            k = nums.size();
        priority_queue<pair<int, int> > pq;
        for (int i = 0; i < k; ++i)
            pq.push(make_pair(nums[i], i));
        for (int i = k; i < nums.size(); ++i) {
            pair<int, int> pr = pq.top();
            retv.push_back(pr.first);
            while (pr.second <= i-k) {
                pq.pop();
                if (pq.empty())
                    break;
                pr = pq.top();
            }
            pq.push(make_pair(nums[i], i));
        }
        retv.push_back(pq.top().first);
        return retv;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
