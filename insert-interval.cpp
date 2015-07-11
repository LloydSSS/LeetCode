// http://www.lintcode.com/zh-cn/problem/insert-interval/
// 水
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

// Definition of Interval:
class Interval{
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ans;
        int i = 0;
        for (; i < intervals.size(); ++i) {
            if (intervals[i].end < newInterval.start) {
                ans.push_back(intervals[i]);
                continue;
            } else if (intervals[i].start > newInterval.end)
                break;

            newInterval.start = min(intervals[i].start, newInterval.start);
            newInterval.end = max(intervals[i].end, newInterval.end);
        }

        ans.push_back(newInterval);
        for (; i < intervals.size(); ++i) {
            ans.push_back(intervals[i]);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
