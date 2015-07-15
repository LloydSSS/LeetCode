// https://leetcode.com/problems/pascals-triangle/
// Time O(n2)
// 动态规划基础题，杨辉三角

#include "lc.h"

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> tri;
        for (int i = 0; i < numRows; ++i) {
            vector<int> line;
            line.push_back(1);
            for (int j = 1; j < i; j++) {
                line.push_back(tri[i-1][j-1]+tri[i-1][j]);
            }
            if (i != 0)
                line.push_back(1);
            tri.push_back(line);
        }
        return tri;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
