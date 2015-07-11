// http://www.lintcode.com/en/problem/minimum-window-substring/
// two-pointer hash table
#include <iostream>
#include <algorithm>
#include <vector>
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
     * @param source: A string
     * @param target: A string
     * @return: A string denote the minimum window
     *          Return "" if there is no such a string
     */
    string minWindow(string &source, string &target) {
        if (target.size() == 0 || target.size() > source.size()) return "";
        string ans;
        vector<int> appeared(256, 0);
        vector<int> expected(256, 0);
        for (int i = 0; i < target.size(); ++i) {
            expected[target[i]]++;
        }

        int left = 0, right = 0;
        int min_width = INT_MAX;
        int count = 0;
        for (int right = 0; right < source.size(); ++right) {
            char c = source[right];
            if (expected[c] > 0) {
                appeared[c]++;
                if (appeared[c] <= expected[c])
                    count++;
            }

            if (count == target.size()) {
                for (; left <= right; ++left) {
                    c = source[left];
                    if (expected[c] == 0)
                        continue;
                    if (appeared[c] > expected[c]) {
                        appeared[c]--;
                    } else
                        break;
                }
                if (right-left+1 < min_width) {
                    min_width = right-left+1;
                    ans = source.substr(left, min_width);
                }
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
