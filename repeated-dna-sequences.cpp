// https://leetcode.com/problems/repeated-dna-sequences/
// hash，纪录出现过的10个长度的序列

#include "lc.h"

class Solution {
public:
    long long hash(string s) {
        long long hs = 0;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case 'A':
                    hs = hs*10;
                    break;
                case 'T':
                    hs = hs*10+1;
                    break;
                case 'C':
                    hs = hs*10+2;
                    break;
                case 'G':
                    hs = hs*10+3;
                    break;
            }
        }
        return hs;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        int len = s.size();
        vector<string> ret;
        set<long long> searched;
        for (int i = 0; i <= len-10; ++i) {
            string sub = s.substr(i, 10);
            if (searched.find(hash(sub)) != searched.end()) {
                if (find(ret.begin(), ret.end(), sub) == ret.end())
                    ret.push_back(sub);
            } else
                searched.insert(hash(sub));
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
