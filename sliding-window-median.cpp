// Sliding Window Maximum
// http://www.lintcode.com/en/problem/sliding-window-median
// a. 优先队列，保存一个窗口的最大值，每次弹出时，同时弹出队首不在窗口内的元素

#include "lc.h"

class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of the element inside the window at each moving
     */
    vector<int> medianSlidingWindow(vector<int> &nums, int k) {
        multiset<int, less<int> > higher;
        multiset<int, greater<int> > lower;
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                if (higher.find(nums[i-k]) != higher.end())
                    higher.erase(higher.find(nums[i-k]));
                else
                    lower.erase(lower.find(nums[i-k]));
            }
            if (lower.empty() && (higher.empty() || nums[i] <= *higher.begin()))
                lower.insert(nums[i]);
            else if (!lower.empty() && nums[i] <= *lower.begin()) {
                if (lower.size() > higher.size()) {
                    higher.insert(*lower.begin());
                    lower.erase(lower.begin());
                }
                lower.insert(nums[i]);
            } else {
                higher.insert(nums[i]);
                if (lower.size() < higher.size()) {
                    lower.insert(*higher.begin());
                    higher.erase(higher.begin());
                }
            }
            if (i >= k-1)
                ans.push_back(*lower.begin());
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> v = {1,2,7,7,2,10,3,4,5};
    auto ans = sol.medianSlidingWindow(v, 2);
    for (int &a : ans)
        cout << a << endl;
    return 0;
}
