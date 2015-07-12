// Jump Game II
// http://www.lintcode.com/en/problem/jump-game-ii/
// a. reach 纪录目前可以到达的最远处，step[i]纪录到达i需要的步数
// b. last纪录之前可以到达的最远处， curr纪录现在可以到达的最远处，如果i到达last之外，则需要新的一步

#include "lintcode.h"

class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        int reach = 0;
        vector<int> step(A.size(), 0);
        for (int i = 0; i < A.size() && i <=reach; ++i) {
            if (A[i] + i > reach) {
                for (int j = reach+1; j <= A[i]+i && j < A.size(); j++)
                    step[j] = step[i]+1;
                reach = A[i]+i;
            }
        }
        return step[A.size()-1];
    }

    int jump2(vector<int> A) {
        int ans = 0, last = 0, curr = 0;
        for (int i = 0; i < A.size(); ++i) {
            if (i > last) {
                if (curr == last)
                    return -1;
                last = curr;
                ans++;
            }
            curr = max(i + A[i], curr);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
