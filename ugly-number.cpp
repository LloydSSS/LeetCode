// http://www.lintcode.com/en/problem/ugly-number
// 使用一个数组保留所有丑数，并且记录当前的最大值，三个指针分别代表3,5,7遍历过得元素，每次前进指针，直到元素*3,5,7大于最大值，比较三者的最小值，即是下一个丑数

#include "lc.h"

class Solution {
public:
    /*
     * @param k: The number k.
     * @return: The kth prime number as description.
     */
    long long kthPrimeNumber(int k) {
        vector<long long> vec;
        vec.push_back(3);
        vec.push_back(5);
        vec.push_back(7);
        long long mx = 7;
        int i3 = 0, i5 = 0, i7 = 0;
        while (vec.size() < k) {
            mx = vec.back();
            long long x = vec[i3]*3, y = vec[i5]*5, z = vec[i7]*7;
            while (x <= mx) {
                i3++;
                x = vec[i3]*3;
            }
            while (y <= mx) {
                i5++;
                y = vec[i5]*5;
            }
            while (z <= mx) {
                i7++;
                z = vec[i7]*7;
            }
            long long minxyz = min(min(x, y), z);
            vec.push_back(minxyz);
        }
        return vec[k-1];
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    cout << sol.kthPrimeNumber(1111) << endl;
    return 0;
}
