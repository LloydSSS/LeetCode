#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
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
