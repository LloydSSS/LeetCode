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
     * @param nums: The integer array.
     * @param target: Target number to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &array, int target) {
        // write your code here
        int l = 0, r = array.size();
        while (l < r) {
            int m = (l+r) >> 1;
            if (array[m] < target)
                l = m+1;
            else if (array[m] >= target)
                r = m;
        }
        if (l < array.size() && array[l] == target) return l;
        return -1;
    }
};



int main(int argc, char const *argv[]) {

	Solution sol;
	return 0;
}
