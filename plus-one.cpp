// http://www.lintcode.com/en/problem/plus-one/
// 注意进位

#include "lc.h"

class Solution {
public:
    /**
     * @param digits a number represented as an array of digits
     * @return the result
     */
    vector<int> plusOne(vector<int>& digits) {
        if (digits.size() == 0) return digits;
        vector<int> ans(digits);
        int n = ans.size();
        for (int i = n-1; i >= 0; --i) {
            ans[i]+=1;
            if (ans[i] == 10)
                ans[i] = 0;
            else
                break;
        }
        if (ans[0] == 0) {
            ans.insert(ans.begin(), 1);
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
