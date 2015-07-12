// http://www.lintcode.com/en/problem/largest-number/
// 第一次面试。。。。

#include "lintcode.h"

bool cmp(string a, string b) {
	return a+b > b+a;
}

class Solution {
public:
    /**
     *@param num: A list of non negative integers
     *@return: A string
     */

    string largestNumber(vector<int> &nums) {
        if (nums.size() == 0) return string("");

        vector<string> strs(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
        	stringstream ss;
			ss<<nums[i];
			ss>>strs[i];
        }
        sort(strs.begin(), strs.end(), cmp);

        if (strs[0] == "0")
        	return strs[0];
        string str;
        for (int i = 0; i < strs.size(); ++i)
        	str.append(strs[i]);
        return str;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	int a[] = {1, 20, 23, 4, 8};
	vector<int> v;
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i) {
        v.push_back(a[i]);
    }
    cout << sol.largestNumber(v) << endl;
	return 0;
}
