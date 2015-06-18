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
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    vector<vector<int> > combine(int n, int k) {
        vector<int> tran(k);
        dfs(tran, 0, n, 0, k);
        return ans;
    }

    vector<vector<int> > ans;
    void dfs(vector<int> &tran, int in, int n, int ik, int k) {
        if (ik == k) {
            ans.push_back(tran);
            return;
        }

        for (int j = in+1; j <= n && n-j+1 >= k-ik; ++j) {
            tran[ik] = j;
            dfs(tran, j, n, ik+1, k);
        }
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
