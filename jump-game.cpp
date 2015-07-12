// Jump Game II
// http://www.lintcode.com/en/problem/jump-game-ii/
// can_reach 纪录目前可以到达的最远处，

#include "lintcode.h"

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
