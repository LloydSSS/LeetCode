// http://www.lintcode.com/zh-cn/problem/merge-intervals/
// 排序后依次合并

#include "lintcode.h"

bool cmp(const Interval &a, const Interval &b) {
    if (a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}

class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() <= 1) return intervals;
        vector<Interval> ans;
        sort(intervals.begin(), intervals.end(), cmp);
        Interval cur = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (cur.end < intervals[i].start) {
                ans.push_back(cur);
                cur = intervals[i];
            } else {
                cur.end = max(cur.end, intervals[i].end);
            }
        }
        ans.push_back(cur);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
