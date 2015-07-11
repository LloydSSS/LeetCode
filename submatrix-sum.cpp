// http://www.lintcode.com/en/problem/submatrix-sum/
// a. Time:O(n2) Space:O(n) 先求出前缀和，然后枚举求两个前缀和的差
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int> > submatrixSum(vector<vector<int>>& matrix) {
        vector<vector<int> > ans;
        int m = matrix.size();
        if (m == 0) return ans;
        int n = matrix[0].size();
        for (int i = 0; i < m; ++i) {
            vector<int> sum(n, 0);
            for (int j = i; j < m; ++j) {
                unordered_map<int, int> hash;
                // sum[k] is the sum of matrix (i, k), (j, k)
                // sum of subarray of sum[k] can be all sub
                // matrix of (i, 0), (j, n-1)
                for (int k = 0; k < n; ++k) {
                    sum[k] += matrix[j][k];
                }

                int target = 0;
                hash[0] = -1;
                for (int k = 0; k < n; ++k) {
                    target += sum[k];
                    if (hash.find(target) != hash.end()) {
                        ans.push_back(vector<int>({i, hash[target]+1}));
                        ans.push_back(vector<int>({j, k}));
                        return ans;
                    }
                    hash[target] = k;
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<vector<int>> matrix = {{1,5,7},{3,7,-8},{4,-8,9}};
    auto ans = sol.submatrixSum(matrix);
	return 0;
}
