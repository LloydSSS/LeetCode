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
     *@param A: A positive integer which has N digits, A is a string.
     *@param k: Remove k digits.
     *@return: A string
     */
    string DeleteDigits(string A, int k) {
		
    	string ans;
    	int j = 0;
		for (int i = 0; i < A.size(); ++i) {
			if (j == 0 || ans[j-1] <= A[i] || k == 0) {
				ans.push_back(A[i]);
				j++;
			}
			else {
				ans.erase(j-1);
				j--;
				i--;
				k--;
			}
		}
		ans.erase(ans.size()-k);
		int prefix_zero = 0;
		while (prefix_zero < ans.size() && ans[prefix_zero] == '0')
			prefix_zero++;
		ans.erase(0, prefix_zero);
		if (ans == "") return "0";
		return ans;
	}
};

int main(int argc, char const *argv[]) {
	Solution sol;
	int a[] = {1, 20, 23, 4, 8};
	vector<int> v;
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i) {
        v.push_back(a[i]);
    }
    cout << sol.DeleteDigits("90249", 1) << endl;
	return 0;
}