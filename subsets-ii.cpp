#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsetsWithDup(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> ss;
        //dfs(ss, 0, nums);
        ans.push_back(vector<int>());
        int oldj = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int stop = 0;
            if (i != 0 && nums[i] == nums[i-1]) {
                stop = oldj;
            }

            oldj = ans.size();
            for (int j = ans.size()-1; j >= stop; --j) {
                ans.push_back(ans[j]);
                ans.back().push_back(nums[i]);
            }
        }
        return ans;
    }
    vector<vector<int> > ans;
    void dfs(vector<int> ss, int i, vector<int> &nums) {
        ans.push_back(ss);
        for (int j = i; j < nums.size(); ++j) {
            if (j != i && nums[j] == nums[j-1])
                continue;
            ss.push_back(nums[j]);
            dfs(ss, j+1, nums);
            ss.pop_back();
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
