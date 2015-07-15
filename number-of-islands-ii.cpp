// http://www.lintcode.com/en/problem/number-of-islands/
// 并查集，每个操作来到时候，查看其相邻元素岛屿的数量

#include "lc.h"

class Solution {
public:
    /**
     * @param n an integer
     * @param m an integer
     * @param operators an array of point
     * @return an integer array
     */
    vector<int> numIslands2(int n, int m, vector<Point>& operators) {
        vector<int> ans;
        int num = 0;
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        for (const auto &point : operators) {
            p[getid(point, m)] = getid(point, m);

            unordered_set<int> neighbors;
            for (const auto &d : directions) {
                Point neighbor(point.x+d.first, point.y+d.second);
                if (neighbor.x >= 0 && neighbor.x < n &&
                    neighbor.y >= 0 && neighbor.y < m &&
                    p.find(getid(neighbor, m)) != p.end()) {
                    neighbors.insert(find_p(getid(neighbor, m)));
                }
            }

            for (const auto &d : directions) {
                Point neighbor(point.x+d.first, point.y+d.second);
                if (neighbor.x >= 0 && neighbor.x < n &&
                    neighbor.y >= 0 && neighbor.y < m &&
                    p.find(getid(neighbor, m)) != p.end()) {
                    union1(getid(point, m), getid(neighbor, m));
                }
            }

            num -= neighbors.size()-1;
            ans.push_back(num);
        }
        return ans;
    }

    int getid(const Point& p, int m) {
        return p.x*m+p.y;
    }

    unordered_map<int, int> p;
    int find_p(int x) {
        if (p.find(x) == p.end()) {
            p[x] = x;
        }
        if (p[x] != x)
            p[x] = find_p(p[x]);
        return p[x];
    }

    void union1(int x, int y) {
        int rootx = find_p(x);
        int rooty = find_p(y);
        p[rootx] = find_p(rooty);
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
