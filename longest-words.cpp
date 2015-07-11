// http://www.lintcode.com/en/problem/longest-words/
// clear不会回收空间，想要回收空间：vector<T>().swap(x);
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
     * @param dictionary: a vector of strings
     * @return: a vector of strings
     */
    vector<string> longestWords(vector<string> &dictionary) {
        int maxlen = 0;
        vector<string> ans;
        for (int i = 0; i < dictionary.size(); ++i) {
            if (dictionary[i].size() > maxlen) {
                maxlen = dictionary[i].size();
                ans.clear();
                ans.push_back(dictionary[i]);
            } else if (dictionary[i].size() == maxlen){
                ans.push_back(dictionary[i]);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
