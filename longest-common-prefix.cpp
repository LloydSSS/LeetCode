#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class Solution {
public:    
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
    	if (strs.size() == 0) return string("");
    	int len = 0;
    	for (; len < strs[0].size(); ++len) {
			for (int i = 1; i < strs.size(); ++i) {
				if (len == strs[i].size() || strs[i][len] != strs[0][len])
					return strs[0].substr(0, len);  
			}
		}
		return strs[0].substr(0, len);   
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
	string s("ABCD");
	string t("ABCEssss");
	vector<string> v;
	v.push_back(s);
	v.push_back(t);
	cout << sol.longestCommonPrefix(v) << endl;
	/* code */
	return 0;
}