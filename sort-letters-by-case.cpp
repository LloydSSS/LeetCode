// http://www.lintcode.com/en/problem/sort-letters-by-case/
// two pointers, 水

#include "lintcode.h"

class Solution {
public:
    /**
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        int left = 0, right = letters.size()-1;
        while (left < right) {
            while (left < right && letters[left] >= 'a' && letters[left] <= 'z')
                left++;
            while (left < right && letters[right] >= 'A' && letters[right] <= 'Z')
                right--;
            if (left < right)
                swap(letters[left], letters[right]);
        }
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
