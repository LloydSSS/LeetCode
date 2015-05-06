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
     * @param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int> > threeSum(vector<int> &nums) {
        vector<vector<int> > res;
        sort(nums.begin(), nums.end());
        int len = nums.size();

        for (int i = 0; i < len; ++i) {
            int j = i+1, k = len-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    vector<int> v;
                    v.push_back(nums[i]);
                    v.push_back(nums[j]);
                    v.push_back(nums[k]);
                    res.push_back(v);
                    j++;
                    k = len-1;
                } else if (sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};


int main(int argc, char const *argv[]) {
    int a[] = {-2,-3,5,-1,-4,5,-11,7,1,2,3,4,-7,-1,-2,-3,-4,-5};
    vector<int> v;
    for (int i = 0; i < 18; ++i) {
        v.push_back(a[i]);
    }
	Solution sol;
    auto res = sol.threeSum(v);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << endl;
    }
	return 0;
}
