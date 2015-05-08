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
    /**
     * param A : an integer sorted array
     * param target :  an integer to be inserted
     * return : an integer
     */
public:
    int searchInsert(vector<int> &A, int target) {
        int l = 0, r = A.size();
        while (l < r) {
            int m = (l+r) >> 1;
            if (A[m] == target)
                return m;
            if (A[m] < target)
                l = m+1;
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
