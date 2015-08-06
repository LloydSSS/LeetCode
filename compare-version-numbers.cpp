// https://leetcode.com/problems/compare-version-numbers/

#include "lc.h"

class Solution {
public:
    vector<int> get_version(string v) {
        int len = v.size();
        int start = 0;
        vector<int> ret;
        for (int i = 1; i < len; ++i) {
            if (v[i] == '.') {
                int x = atoi(v.substr(start, i-start+1).c_str());
                ret.push_back(x);
                start = i+1;
                i = start;
            }
        }
        int x = atoi(v.substr(start, len-start+1).c_str());
        ret.push_back(x);
        return ret;
    }
    int compareVersion(string version1, string version2) {
        vector<int> v1 = get_version(version1);
        vector<int> v2 = get_version(version2);
        int len1 = v1.size();
        int len2 = v2.size();
        if (len1 < len2)
            for (int i = 0; i < len2-len1; ++i) v1.push_back(0);
        else if (len1 > len2)
            for (int i = 0; i < len1-len2; ++i) v2.push_back(0);

        for (int i =0; i < min(v1.size(), v2.size()); ++i) {
            if (v1[i] > v2[i]) return 1;
            if (v1[i] < v2[i]) return -1;
        }
        return 0;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
