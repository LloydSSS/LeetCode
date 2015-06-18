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
     * @param nums: A list of integers.
     * @return: A list of unique permutations.
     */
    vector<vector<int> > permuteUnique(vector<int> &nums) {
        if (nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return ans;
    }
    vector<vector<int> > ans;
    void dfs(vector<int> perm, int i) {
        if (i == perm.size()) {
            ans.push_back(perm);
            return;
        }
        for (int j = i; j < perm.size(); ++j) {
            if (j != i && perm[j] == perm[i])
                continue;
            swap(perm[i], perm[j]);
            dfs (perm, i+1);
            //swap(perm[i], perm[j]);
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
