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
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        if (A.size() == 0 || B.size() == 0) return 0;
        vector<vector<int> > dp(A.size()+1, vector<int>(B.size()+1, 0));
        for (int i = 1; i <= A.size(); ++i) {
            for (int j = 1; j <= B.size(); ++j) {
                if (A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[A.size()][B.size()];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
