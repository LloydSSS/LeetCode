#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param s: The first string
     * @param b: The second string
     * @return true or false
     */
    bool anagram(string s, string t) {
    	if (s.size() != t.size()) return false;

        vector<int> ms(256, 0);
        vector<int> mt(256, 0);
        for (int i = 0; i < s.size(); ++i) {
        	ms[s[i]]++;
        	mt[t[i]]++;
        }
        for (int i = 0; i < 256; ++i) {
        	if (ms[i] != mt[i]) return false;
        }
        return true;
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
	cout << sol.anagram("aabb", "bbaa") << endl;
	/* code */
	return 0;
}