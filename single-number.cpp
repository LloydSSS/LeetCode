#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
    	if (A.size() == 0) return 0;
        int ans = A[0];
        for (int i = 1; i < A.size(); ++i)
        	ans ^= A[i]
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}