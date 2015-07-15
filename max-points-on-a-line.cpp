// http://www.lintcode.com/en/problem/max-points-on-a-line/
// https://leetcode.com/problems/max-points-on-a-line/
// 注意重复点以及垂直x轴的线

#include "lc.h"

class Solution {
public:
    /**
     * @param points an array of point
     * @return an integer
     */
    int maxPoints(vector<Point>& points) {
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            int dup = 1;
            unordered_map<double, int> mp;
            for (int j = i+1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    dup++;
                    continue;
                }
                if (points[i].x == points[j].x)
                    mp[INT_MAX]++;
                else {
                    double k = static_cast<double>(points[i].y-points[j].y) /
                                static_cast<double>(points[i].x-points[j].x);
                    mp[k]++;
                }
            }
            if (dup > ans)
                ans = dup;
            for(auto pr : mp) {
                ans = max(ans, pr.second+dup);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
