// k Sum II
// http://www.lintcode.com/en/problem/k-sum-ii/
// dfs
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
     * @param A: an integer array.
     * @param k: a positive integer (k <= length(A))
     * @param target: a integer
     * @return a list of lists of integer
     */
    vector<vector<int> > kSumII(vector<int> A, int k, int target) {
        sort(A.begin(), A.end());
        vector<int> tran;
        dfs(A, k, target, 0, tran);
        return ans;
    }

    vector<vector<int> > ans;
    void dfs(vector<int> &A, int k, int target, int idx, vector<int> &tran) {
        if (k == 0) {
            if (target == 0)
                ans.push_back(tran);
            return;
        }
        if (idx == A.size() || A[idx] > target) return;
        for (int i = idx; i < A.size(); ++i) {
            if (A[i] > target) break;
            tran.push_back(A[i]);
            dfs(A, k-1, target - A[i], i+1, tran);
            tran.pop_back();
        }
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
