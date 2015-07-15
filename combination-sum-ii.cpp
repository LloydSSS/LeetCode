// http://www.lintcode.com/en/problem/combination-sum-ii/
// https://leetcode.com/problems/combination-sum-ii/
// dfs+剪枝，注意重复值的处理

#include "lc.h"

class Solution {
public:
    /**
     * @param num: Given the candidate numbers
     * @param target: Given the target number
     * @return: All the combinations that sum to target
     */
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        vector<int> tran;
        dfs (num, tran, 0, target);
        return ans;
    }

    vector<vector<int> > ans;
    void dfs(vector<int> &candidates, vector<int> &tran, int i, int target) {
        if (target == 0) {
            ans.push_back(tran);
        }
        for (int j = i; j < candidates.size() && candidates[j] <= target; j++) {
            if (j > i && candidates[j] == candidates[j-1])
                continue;
            tran.push_back(candidates[j]);
            dfs(candidates, tran, j+1, target-candidates[j]);
            tran.pop_back();
        }
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
