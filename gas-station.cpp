// http://www.lintcode.com/en/problem/gas-station/
// https://leetcode.com/problems/gas-station/
// 贪心，sum表示总的汽油量减消耗量，local_sum表示从ans开始的结果，如果sum>=0则一定可以完成，起点可以是任意可以使local_sum>=0的开始节点

#include "lc.h"

class Solution {
public:
    /**
     * @param gas: a vector of integers
     * @param cost: a vector of integers
     * @return: an integer
     */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int ans = 0;
        int sum = 0;
        int local_sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
        	int remain = gas[i] - cost[i];
        	sum += remain;
        	local_sum += remain;
        	if (local_sum < 0) {
        		local_sum = 0;
        		ans = i+1;
        	}
        }
        if (sum < 0)
        	return -1;
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
