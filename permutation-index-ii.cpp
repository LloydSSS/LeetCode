// http://www.lintcode.com/en/problem/permutation-index-ii/
// http://stackoverflow.com/questions/14212030/number-to-unique-permutation-mapping-of-a-sequence-containing-duplicates
//

#include "lc.h"

// Time:  O(N^3)
// Space: O(N)
class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        int n = A.size();
        long long ans = 1;

        vector<long long> base(n+1, 1);
        for (size_t i = 1; i <= n; ++i)
            base[i] = base[i-1]*i;
        base[0] = 0;
        unordered_map<int, int> num_to_count;
        num_to_count[A.back()]++;
        int all_count = 0;
        for (int i = A.size()-2; i >= 0; --i) {
            num_to_count[A[i]]++;
            all_count++;
            unordered_map<int, int> small_to_count;
            for (int j = A.size()-1; j > i; --j) {
                if (A[i] > A[j]) {
                    small_to_count[A[j]]++;
                }
            }

            for (const auto &kvp : small_to_count) {
                long long perm_num = base[all_count];
                num_to_count[kvp.first]--;
                for (const auto &kvp2 : num_to_count) {
                    if (kvp2.second == 0)
                        continue;
                    perm_num /= base[kvp2.second];
                }
                ans += perm_num;
                num_to_count[kvp.first]++;
            }
        }
        return ans;
    }
};

// Time:  O(N^2)
// Space: O(N)
class Solution2 {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
    long long permutationIndexII(vector<int>& A) {
        long long index = 1;
        // Position 1 is paired with factor 0 and so is skipped.
        int position = 2;
        long long factor = 1;
        unordered_map<int, int> number_to_count;
        ++number_to_count[A.back()];
        for (int i = static_cast<int>(A.size()) - 2; i >= 0; --i) {
            unordered_map<int, int> successor_to_count;
            ++number_to_count[A[i]];
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] > A[j]) {
                    ++successor_to_count[A[j]];
                }
            }
            for (const auto& kvp : successor_to_count) {
                index += factor * kvp.second / number_to_count[A[i]];
            }
            factor = factor * position / number_to_count[A[i]];
            ++position;
        }
        return index;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<int> v = {3,2,2,1,1,1};
    cout << sol.permutationIndexII(v) << endl;
	return 0;
}
