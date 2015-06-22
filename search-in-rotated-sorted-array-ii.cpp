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

// plan 1: 直接二分
// plan 2: 先找到转折点，再二分
class Solution {
    /**
     * param A : an integer ratated sorted array and duplicates are allowed
     * param target :  an integer to be search
     * return : a boolean
     */
public:
    bool search(vector<int> &A, int target) {
        int left = 0, right = A.size();
        while (left < right) {
            int mid = (left+right)/2;
            if (A[mid] == target)
                return true;
            if (A[left] < A[mid]) {
                if (A[left] <= target && A[mid] > target)
                    right = mid;
                else
                    left = mid+1;
            } else if (A[left] > A[mid]) {
                if (A[mid] < target && A[right-1] >= target)
                    left = mid+1;
                else
                    right = mid;
            } else
                left++;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;

	return 0;
}
