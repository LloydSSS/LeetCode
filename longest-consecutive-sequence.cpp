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
     * @param nums: A list of integers
     * @return an integer
     */
    int longestConsecutive(vector<int> &num) {
        unordered_set<int> ust;
        for (int i = 0; i < num.size(); ++i)
            ust.insert(num[i]);
        int ans = 0;
        for (int i = 0; i < num.size(); ++i) {
            ans = max(ans, find_bound(ust, num[i]));
        }
        return ans;
    }

    int find_bound(unordered_set<int> &ust, int x) {
        int len = 0;
        unordered_set<int>::iterator usti;
        int upper = x;
        while (ust.find(upper) != ust.end()) {
            len++;
            ust.erase(upper++);
        }
        int lower = x-1;
        while (ust.find(lower) != ust.end()) {
            len++;
            ust.erase(lower--);
        }
        return len;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;

    return 0;
}
