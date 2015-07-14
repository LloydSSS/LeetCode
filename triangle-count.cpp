// http://www.lintcode.com/en/problem/triangle-count/
// a.排序，遍历最长边与最短边，二分查找中间边
// b.three-pointers

#include "lintcode.h"

class Solution {
public:
    /**
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        int ans = 0;
        sort(S.begin(), S.end());
        for (int i = 0; i < S.size()-2; ++i) {
            for (int j = i+2; j < S.size(); ++j) {
                int target = S[j]-S[i];
                // find k , S[k] > target
                int left = i+1, right = j;
                while (left < right) {
                    int mid = (left+right)/2;
                    if (S[mid] > target) {
                        right = mid;
                    } else
                        left = mid+1;
                }
                ans += j-left;
            }
        }
        return ans;
    }

    int triangleCount2(vector<int> &S) {
        int ans = 0;
        sort(S.begin(), S.end());
        int k = 1;
        for (int i = 0; i < S.size()-2; ++i) {
            k = max(k, i+1);
            for (int j = i+2; j < S.size(); ++j) {
                k = min(k, j-1);
                int target = S[j]-S[i];
                // find k , S[k] > target
                while (k < j && S[k] <= target)
                    k++;
                ans += j-k;
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
