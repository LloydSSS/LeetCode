// http://www.lintcode.com/en/problem/hash-function/
// Magic Number is what?
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
     * @param key: A String you should hash
     * @param HASH_SIZE: An integer
     * @return an integer
     */
    int hashCode(string key,int HASH_SIZE) {
        long long base = 1;
        long long hash = 0;
        for (int i = key.size()-1; i >= 0; --i) {
            hash = (hash + base*key[i])%HASH_SIZE;
            base = (base*33)%HASH_SIZE;
        }
        return static_cast<int>(hash);
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
