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
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
    int replaceBlank(char *str, int length) {
        if (str == nullptr) return 0;
        int space_num = 0;
        for (int i = 0; i < length; ++i)
            if (str[i] == ' ') space_num++;
        int newlen = length + space_num*2;
        int j = newlen;
        for (int i = length; i >= 0; --i) {
            if (str[i] != ' ')
                str[j--] = str[i];
            else {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            }
        }
        return newlen;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    char str[1000];
    strcpy(str, "hello world");
    cout << str << endl;
    sol.replaceBlank(str, strlen(str));
    cout << str << endl;
    return 0;
}
