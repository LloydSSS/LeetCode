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
     * param A : an integer ratated sorted array
     * param target :  an integer to be searched
     * return : an integer
     */
public:
    int search(vector<int> &A, int target) {
        int left = 0, right = A.size();
        while (left < right) {
            int mid = (left+right)/2;
            if (A[mid] == target)
                return mid;
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
        return -1;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;

	return 0;
}
