// http://www.lintcode.com/en/problem/wood-cut/
// O(nlogL)
// 对长度进行二分搜索

#include "lc.h"

class Solution {
public:
    /**
     *@param L: Given n pieces of wood with length L[i]
     *@param k: An integer
     *return: The maximum length of the small pieces.
     */
    int woodCut(vector<int> L, int k) {
        int shortest = 1, longest = 1;
        int len = L.size();
        int ans = 0;
        for (int i = 0; i < len; ++i)
            if (L[i] > longest) longest = L[i];
        while (shortest <= longest) {
            int mid = (longest-shortest)/2 + shortest;
            int cnt = 0;
            for (int i = 0; i < len; ++i)
                cnt += L[i]/mid;
            if (cnt >= k) {
                ans = mid;
                shortest = mid+1;
            } else
                longest = mid-1;
        }
        return ans;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    int a[] = {232,124,456};
    vector<int> v;
    for (int i = 0; i < sizeof(a)/sizeof(int); ++i) {
        v.push_back(a[i]);
    }
    cout << sol.woodCut(v, 7)<< endl;
	return 0;
}
