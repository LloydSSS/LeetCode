// http://www.lintcode.com/en/problem/kth-smallest-number-in-sorted-matrix/#
// 使用堆来维护，每次弹出当前最小值，然后将它的右边及下面元素加入堆，注意不要重复加入，使用set来纪录访问过的元素，不知道为什么使用unordered_set无法编译通过

#include "lc.h"

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @param k: an integer
     * @return: the kth smallest number in the matrix
     */
    int kthSmallest(vector<vector<int> > &matrix, int k) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        priority_queue<pair<int, pair<int,int> >,
                vector<pair<int, pair<int,int> > >,
                greater<pair<int, pair<int,int> > > > pq;
        set<pair<int,int> > used;
        pq.push(make_pair(matrix[0][0], make_pair(0, 0)));
        used.insert(make_pair(0, 0));
        while (k-- && !pq.empty()) {
            pair<int, pair<int,int> > ppr = pq.top();
            // cout << ppr.first << endl;
            pq.pop();
            if (k == 0)
                return ppr.first;
            int x = ppr.second.first;
            int y = ppr.second.second;
            auto right = make_pair(x+1, y);
            if (x + 1 < n && used.find(right) == used.end()) {
                pq.push(make_pair(matrix[x+1][y], right));
                used.insert(right);
            }
            auto down = make_pair(x, y+1);
            if (y + 1 < m && used.find(down) == used.end()) {
                pq.push(make_pair(matrix[x][y+1], down));
                used.insert(down);
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<vector<int> > vv = {{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8}};
    cout << sol.kthSmallest(vv, 19) << endl;
    return 0;
}
