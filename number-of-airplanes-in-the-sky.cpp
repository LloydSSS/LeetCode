// http://www.lintcode.com/en/problem/number-of-airplanes-in-the-sky/
// 将区间开始和结束放在一起排序，注意标记开始和结束，于是就转换成求括号序列的最大嵌套，使用一个计数器，遇见开始++，遇见结束--，过程中最大的计数就是答案，注意结束标记的权值要小于开始标记，这样排序时候就可以保证同一时间先降落再起飞

#include "lc.h"

bool cmp(const Interval &a, const Interval &b) {
    if (a.start == b.start)
        return a.end < b.end;
    return a.start < b.start;
}

class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        vector<pair<int, int> > timelines;
        for (int i = 0; i < airplanes.size(); ++i) {
            timelines.push_back(make_pair(airplanes[i].start, 1));
            timelines.push_back(make_pair(airplanes[i].end, 0));
        }
        sort(timelines.begin(), timelines.end());

        int ans = 0;
        int count = 0;
        for (auto &pii : timelines) {
            if (pii.second == 0)
                count--;
            else
                count++;
            ans = max(ans, count);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<Interval> airp;
    airp.push_back(Interval(10, 14));
    airp.push_back(Interval(10, 15));
    airp.push_back(Interval(10, 16));
    airp.push_back(Interval(1, 10));
    airp.push_back(Interval(2, 10));
    airp.push_back(Interval(3, 10));
    airp.push_back(Interval(4, 10));
    cout << sol.countOfAirplanes(airp) << endl;
    return 0;
}
