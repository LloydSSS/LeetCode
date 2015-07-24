// http://www.lintcode.com/en/problem/nuts-bolts-problem/#
// http://www.geeksforgeeks.org/nuts-bolts-problem-lock-key-problem/
// 寻找对应关系
// This algorithm first performs a partition by picking last element of bolts array as pivot, rearrange the array of nuts and returns the partition index ‘i’ such that all nuts smaller than nuts[i] are on the left side and all nuts greater than nuts[i] are on the right side. Next using the nuts[i] we can partition the array of bolts. Partitioning operations can easily be implemented in O(n). This operation also makes nuts and bolts array nicely partitioned. Now we apply this partitioning recursively on the left and right sub-array of nuts and bolts.
// As we apply partitioning on nuts and bolts both so the total time complexity will be Θ(2*nlogn) = Θ(nlogn) on average.
// Here for the sake of simplicity we have chosen last element always as pivot. We can do randomized quick sort too.

#include "lc.h"


class Comparator {
public:
    int cmp(string a, string b) { return 0;}
};
/**
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        sortHelper(nuts, bolts, compare, 0, nuts.size()-1);
    }

    void sortHelper(vector<string> &nuts, vector<string> &bolts, Comparator &compare, int left, int right) {
        if (left >= right)
            return;

        // Choose last element of bolts array for nuts partition.
        int pivot = partition(nuts, compare, left, right, bolts[right]);
        // Now using the partition of nuts choose that for bolts partition.
        partition(bolts, compare, left, right, nuts[pivot]);

        // Recur for [left...pivot-1] & [pivot+1...right] for nuts and bolts array.
        sortHelper(nuts, bolts, compare, left, pivot-1);
        sortHelper(nuts, bolts, compare, pivot+1, right);
    }

    int partition(vector<string> &vec, Comparator &compare, int left, int right, string pivot) {
        int j = left;
        for (int i = left; i < right; ++i) {
            int ret = compare.cmp(vec[i], pivot);
            if (ret == -1) {
                swap(vec[i], vec[j]);
                j++;
            } else if (ret == 0) {
                swap(vec[i], vec[right]);
                i--;
            } else if (ret == 2) {
                ret = compare.cmp(pivot, vec[i]);
                if (ret == 1) {
                    swap(vec[i], vec[j]);
                    j++;
                } else if (ret == 0) {
                    swap(vec[i], vec[right]);
                    i--;
                }
            }
        }
        swap(vec[j], vec[right]);
        return j;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
