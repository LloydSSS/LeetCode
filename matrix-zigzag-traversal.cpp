// http://www.lintcode.com/zh-cn/problem/matrix-zigzag-traversal/
// dp+dfs
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: a matrix of integers
     * @return: a vector of integers
     */
    vector<int> printZMatrix(vector<vector<int> > &matrix) {
        vector<int> ans;
        if (matrix.size()== 0 || matrix[0].size() == 0) return ans;
        int m = matrix.size(), n = matrix[0].size();
        int maxlen = max(m-1, n-1) * max(m-1, n-1) + 1;
        for (int len = 0; len <= maxlen; ++len) {
            if (len%2) {
                for (int i = 0; i <= min(len, m-1); ++i) {
                    int j = len-i;
                    if (j >= n)
                        continue;
                    ans.push_back(matrix[i][j]);
                }
            } else {
                for (int j = 0; j <= min(len, n-1); ++j) {
                    int i = len-j;
                    if (i >= m)
                        continue;
                    ans.push_back(matrix[i][j]);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<vector<int> > mat = {{1,2}, {1,2}};
    vector<int> ans = sol.printZMatrix(mat);
    for (int i = 0; i < ans.size(); ++i)
        cout << ans[i];
	return 0;
}
