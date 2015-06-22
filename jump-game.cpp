#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: The boolean answer
     */
    bool canJump(vector<int> A) {
    	int can_reach = 0;
    	for (int i = 0; i < A.size(); ++i)
    		if (i <= can_reach) {
    			can_reach = max(i+A[i], can_reach);
    			if (can_reach >= A.size())
    				break;
    		}

    	return can_reach >= A.size();
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
