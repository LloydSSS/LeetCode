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
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    int lower_bound(vector<int> &A, int target) {
        int l = 0, r = A.size();
        while (l < r) {
            int m = (l+r) >> 1;
            if (A[m] < target)
                l = m+1;
            else
                r = m;
        }
        return l;
    }
    int upper_bound(vector<int> &A, int target) {
        int l = 0, r = A.size();
        while (l < r) {
            int m = (l+r) >> 1;
            if (A[m] <= target)
                l = m+1;
            else
                r = m;
        }
        return l;
    }

    vector<int> searchRange(vector<int> &A, int target) {
        int lower = lower_bound(A, target);
        int upper = upper_bound(A, target);
        if (lower == A.size() || A[lower] != target)
            return vector<int>(2, -1);
        vector<int> result;
        result.push_back(lower);
        result.push_back(upper);
        return result;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
    int a[] = {9,10,100,101,1002,10203};
    vector<int> v;
    for (int i = 0; i < sizeof(a)/sizeof(int); ++i) {
        v.push_back(a[i]);
    }
    vector<int> result = sol.searchRange(v, 10203);
    cout << result[0] << " " << result[1] << endl;
	return 0;
}
