// Reverse Words in a String
// http://www.lintcode.com/en/problem/reverse-words-in-a-string/
// a. 先做预处理，去掉多余空格，然后整体翻转，再对每个单词翻转，使用了algorithm的函数reverse [first, end)
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
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
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        string t;
        bool preisspace = true;
        int gap = s.find_last_not_of(' ');
        for (int i = 0; i <= gap; ++i) {
            if (preisspace && s[i] == ' ')
                continue;
            t += s[i];
            if (s[i] == ' ')
                preisspace = true;
            else
                preisspace = false;
        }
        reverse(t.begin(), t.end());
        string::iterator iter1 = t.begin();
        string::iterator iter2 = t.begin();
        while (true) {
            while (iter2 != t.end() && *iter2 != ' ')
                iter2++;
            reverse(iter1, iter2);
            if (iter2 == t.end()) break;
            iter1 = iter2 = iter2+1;
        }
        return t;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    cout << sol.reverseWords(" ") << endl;
    return 0;
}
