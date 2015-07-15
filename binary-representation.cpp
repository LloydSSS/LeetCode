// http://www.lintcode.com/en/problem/binary-representation/
// Time, Space O(n)
// 整数部分和小数部分要分开处理stoi，stod，否则会因为精度问题出错
#include "lc.h"

class Solution {
public:
    /**
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
    string binaryRepresentation(string n) {
        int i = stoi(n.substr(0, n.find('.')));
        double d = stod(n.substr(n.find('.')));
        string it = parseInt(i);
        string flt = parseDouble(d);
        if (flt == "ERROR")
            return flt;
        if (flt == "")
            return it;
        return it + "." + flt;
    }

    string parseInt(int n) {
        if (n == 0) return "0";
        string ans;
        while (n) {
            ans = (n%2 ? "1": "0") + ans;
            n >>= 1;
        }
        return ans;
    }

    // 无法处理精度问题
    string parseDouble(double d) {
        string ans;
        while (d > 0) {
            if (ans.size() > 32)
                return "ERROR";
            d *= 2;
            if (d >= 1) {
                ans += "1";
                d = d-1;
            } else
                ans += "0";
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	cout << sol.binaryRepresentation("3.72") << endl;
	return 0;
}
