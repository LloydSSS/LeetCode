#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
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
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */

    bool ok(vector<int> &tran, int x, int y) {
        for (int i = 0; i < y; ++i) {
            if (tran[i] == x || abs(x - tran[i]) == y - i)
                return false;
        }
        return true;
    }

    vector<string> print(vector<int> &tran) {
        vector<string> retv;
        for (int i = 0; i < tran.size(); ++i) {
            string line(tran.size(), '.');
            line[tran[i]] = 'Q';
            retv.push_back(line);
        }
        return retv;
    }

    void dfs(vector<int> &tran, int y, vector<vector<string> > &ans) {
        int n = tran.size();
        if (y == n) {
            ans.push_back(print(tran));
            return;
        }

        for (int x = 0; x < n; ++x) {
            if (ok(tran, x, y)) {
                tran[y] = x;
                dfs(tran, y+1, ans);
            }
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > ans;
        vector<int> tran(n);
        dfs(tran, 0, ans);
        return ans;
        int x = 0, y = 0;
        while (y < n) {
            while (x < n) {
                if (ok(tran, x, y)) {
                    tran[y] = x;
                    if (y+1 == n) {
                        ans.push_back(print(tran));
                        if (y)
                            y--;
                        x = tran[y]+1;

                    } else {
                        x = 0;
                        y++;
                    }
                } else {
                    x++;
                }
            }
            while (x == n) {
                if (y == 0)
                    return ans;
                y--;
                x = tran[y]+1;
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
