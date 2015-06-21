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
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int l = 0, r = nums.size()-1;

        while (true) {
            while (l <= r && nums[l]%2 == 1) l++;
            while (r >= l && nums[r]%2 == 0) r--;
            if (l >= r) break;
            swap(nums[l], nums[r]);
        }
    }
};


int main(int argc, char const *argv[]) {

	Solution sol;
    std::vector<int> v;
    int a[7] = {1,2,3,4,5,6,7};
    for (int i = 0; i < 7; ++i)
    {
        v.push_back(a[i]);
    }
    sol.partitionArray(v);
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
    }
	return 0;
}
