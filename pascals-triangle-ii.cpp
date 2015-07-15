// https://leetcode.com/problems/pascals-triangle-ii/
// Time O(n2)
// 动态规划基础题，杨辉三角

#include "lc.h"

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> line(rowIndex+1);
        line[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = rowIndex; j > 0; --j) {
                line[j] = line[j-1] + line[j];
            }
        }
        return line;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
