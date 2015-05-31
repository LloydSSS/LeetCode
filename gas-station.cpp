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