// http://www.lintcode.com/en/problem/fizz-buzz/
// 水。。。

#include "lintcode.h"

class Solution {
public:
    /**
     * param n: As description.
     * return: A list of strings.
     */
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for (int i = 1; i <= n; i++) {
            if (i % 15 == 0) {
                ans.push_back("fizz buzz");
            } else if (i % 5 == 0) {
                ans.push_back("buzz");
            } else if (i % 3 == 0) {
                ans.push_back("fizz");
            } else {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
