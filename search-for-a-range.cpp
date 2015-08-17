// http://www.lintcode.com/en/problem/search-for-a-range/
// 寻找上界下界, 寻找下界时候，如果使用左闭右闭，则必须m = (l+r+1) >> 1;否则需要特殊处理

#include "lc.h"

class Solution {
    /**
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    int lower_bound(vector<int> &A, int target) {
        int l = 0, r = A.size()-1;
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
        int l = 0, r = A.size()-1;
        while (l < r) {
            int m = (l+r+1) >> 1;
            if (A[m] > target)
                r = m-1;
            else
                l = m;
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

class Solution2 {
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
            return vector<int> {-1, -1};
        return vector<int> {lower, upper-1};
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    int a[] = {-1,0,1,2,2,2,3,3,3,4,4,4,5,5,6,90,92,93,101};
    vector<int> v;
    for (int i = 0; i < sizeof(a)/sizeof(int); ++i) {
        v.push_back(a[i]);
    }
    vector<int> result = sol.searchRange(v, 2);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
