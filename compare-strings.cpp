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
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
    	vector<string> res;
        map<string, vector<string> > mp;
        for (int i = 0; i < strs.size(); ++i) {
        	string ss = strs[i];
        	sort(ss.begin(), ss.end());
        	if (mp.find(ss) == mp.end()) {
        		mp[ss] = vector<string>(1, strs[i]);
        	} else {
        		mp[ss].push_back(strs[i]);
        	}
        }
        for (map<string, vector<string> >::iterator it = mp.begin(); it != mp.end(); it++) {
        	if (it->second.size() != 1) {
        		res.insert(res.end(), it->second.begin(), it->second.end());
        	}
        }
        return res;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
	std::vector<string> v;
	v.push_back("lint");
	v.push_back("intl");
	v.push_back("inlt");
	v.push_back("code");
	std::vector<string> res = sol.anagrams(v);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
	//cout << sol.compareStrings("ABCD", "ABCA") << endl;
	/* code */
	return 0;
}