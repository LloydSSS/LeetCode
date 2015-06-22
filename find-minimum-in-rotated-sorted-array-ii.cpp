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
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int l = 0, r = num.size()-1;
        while (l < r) {
            while (num[l] == num[r] && l < r)
                l++;
            int m = (l+r) >> 1;
            if (num[l] > num[m])
                r = m;
            else if (num[m] > num[r])
                l = m+1;
            else
                break;
        }
        return num[l];
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v = {999,999,1000,1000,10000,0,999,999,999};

    cout << sol.findMin(v) << endl;
	return 0;
}
