// https://leetcode.com/problems/combination-sum-iii/
// dfs+剪枝，注意重复值的处理

#include "lc.h"

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num;
        for (int i = 1; i <= 9; ++i)
            num.push_back(i);
        return combinationSum2(num, k, n);
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int k, int target) {
        sort(num.begin(), num.end());
        vector<int> tran;
        dfs (num, tran, 0, k, target);
        return ans;
    }

    vector<vector<int> > ans;
    void dfs(vector<int> &candidates, vector<int> &tran, int i, int k, int target) {
        if (tran.size() > k)
            return;
        if (tran.size() == k) {
            if (target == 0)
                ans.push_back(tran);
            return;
        }
        for (int j = i; j < candidates.size() && candidates[j] <= target; j++) {
            if (j > i && candidates[j] == candidates[j-1])
                continue;
            tran.push_back(candidates[j]);
            dfs(candidates, tran, j+1, k, target-candidates[j]);
            tran.pop_back();
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
