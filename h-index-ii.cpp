// https://leetcode.com/problems/h-index-ii/
// 二分搜索 []

#include "lc.h"

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n-1;
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (citations[mid] < n-mid)
                left = mid+1;
            else
                right = mid-1;
        }
        return n-left;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
