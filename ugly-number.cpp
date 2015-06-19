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
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        vector<long long> vec;
        vec.push_back(3);
        vec.push_back(5);
        vec.push_back(7);
        long long mx = 7;
        int i3 = 0, i5 = 0, i7 = 0;
        while (vec.size() < k) {
            mx = vec.back();
            long long x = vec[i3]*3, y = vec[i5]*5, z = vec[i7]*7;
            while (x <= mx) {
                i3++;
                x = vec[i3]*3;
            }
            while (y <= mx) {
                i5++;
                y = vec[i5]*5;
            }
            while (z <= mx) {
                i7++;
                z = vec[i7]*7;
            }
            long long minxyz = min(min(x, y), z);
            vec.push_back(minxyz);
        }
        return vec[k-1];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    cout << sol.kthPrimeNumber(1111) << endl;
    return 0;
}
