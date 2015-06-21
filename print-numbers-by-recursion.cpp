#include <iostream>
#include <sstream>
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
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    vector<int> numbersByRecursion(int n) {
        if (n <= 0) return ans;
        string num(n, '0');
        dfs(num, 0, n);
        return ans;
    }
    vector<int> ans;
    void dfs(string &num, int idx, int n) {
        if (idx == n) {
            int i = atoi(num);
            if (i != 0)
                ans.push_back(i);
            return;
        }
        for (int i = 0; i < 10; ++i) {
            num[idx] = i +'0';
            dfs(num, idx+1, n);
        }
    }
    
    int atoi(const string &s) {
        int i;
        stringstream ss;
        ss << s;
        ss >> i;
        return i;
    }
};

int main(int argc, char const *argv[]) {

	Solution sol;
    std::vector<int> v;
    
    v = sol.numbersByRecursion(2);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
	return 0;
}
