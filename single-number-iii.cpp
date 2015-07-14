// Single Number II
// http://www.lintcode.com/en/problem/single-number-ii/
// a. xsum = a^b，根据xsum中不为0的一位将A分为两部分，a,b分别在两部分

#include "lintcode.h"

class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        vector<int> ans;
        int xsum = 0;
        for (int i = 0; i < A.size(); ++i)
            xsum ^= A[i];
        int flag = xsum & (~(xsum-1));
        if (flag == 0) return ans;
        int a = 0, b = 0;
        for (int i = 0; i < A.size(); ++i)
            if (A[i]&flag) a ^= A[i];
            else b ^= A[i];
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
