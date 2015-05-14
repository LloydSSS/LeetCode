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
     *@param n: Given a decimal number that is passed in as a string
     *@return: A string
     */
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
    	set<double> st;
    	while (d > 0) {
    		if (ans.size() > 17 && st.find(d) != st.end())
    			return "ERROR";
    		st.insert(d);
    		d *= 2;
    		if (d >= 1) {
    			ans += "1";
    			d = d-1;
    		} else
    			ans += "0";
    	}
    	return ans;
    }
    string binaryRepresentation(string n) {
    	double d = atof(n.c_str());
    	cout << sizeof() << endl;
    	int i = d;
        string it = parseInt(i);
        string flt = parseDouble(d-i);
        if (flt == "ERROR")
        	return flt;
        if (flt == "")
        	return it;
        return it + "." + flt;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	cout << sol.binaryRepresentation("3.72") << endl;
	return 0;
}