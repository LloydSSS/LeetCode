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
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        vector<int> dp(m, 1);
        for (int i = 1; i < n; ++i) {
        	for (int j = 1; j < m; ++j)
        		dp[j] = dp[j] + dp[j-1];
        }
        return dp[m-1];
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
	cout << sol.uniquePaths(2, 3) << endl;
	return 0;
}