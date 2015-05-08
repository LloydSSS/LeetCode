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
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        int l = 0, r = A.size();
        while (l < r) {
            int m = (l+r) >> 1;
            if (m == l)
                return m;
            else if (m+1 == r)
                return A[m]>A[m-1] ? m : m-1;
            if (A[m-1] < A[m] && A[m] > A[m+1]) return m;
            if (A[m-1] < A[m])
                l = m;
            else
                r = m;
        }
        return l;
    }
};



int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
