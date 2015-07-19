// http://www.lintcode.com/en/problem/delete-digits/
// 想让一个数字尽可能小，那么就要把小的数字尽量放到前面，如果前面有比它大的数字，那么就到把在它前面且比它大的数字都要删除掉，直到已经删掉k个数字。剩下的就是一些特殊情况与边界情况了，比如前置0要去掉，如果遍历一遍发现删除的数字还不足k个，那么就把最后的k-cnt个删除掉。

#include "lc.h"

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
			} else {
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

    string DeleteDigits2(string A, int k) {
        string s;
        if (k > A.size()) return s;
        int cnt = 0;
        for (int i = 0; i < A.size(); ++i) {
            while (!s.empty() && s.back() > A[i] && cnt < k) {
                s.pop_back();
                ++cnt;
            }
            if (A[i] != '0' || !s.empty()) s.push_back(A[i]);
        }
        if (cnt < k) s.resize(s.size() - k + cnt);
        return s;
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
