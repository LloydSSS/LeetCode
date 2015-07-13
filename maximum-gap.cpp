// http://www.lintcode.com/zh-cn/problem/lru-cache/
// a. 排序
// b. 桶排序
// Suppose there are N elements and they range from A to B.
// Then the maximum gap will be no smaller than ceiling[(B - A) / (N - 1)]
// Let the length of a bucket to be len = ceiling[(B - A) / (N - 1)], then we will have at most num = (B - A) / len + 1 of bucket
//for any number K in the array, we can easily find out which bucket it belongs by calculating loc = (K - A) / len and therefore maintain the maximum and minimum elements in each bucket.
// Since the maximum difference between elements in the same buckets will be at most len - 1, so the final answer will not be taken from two elements in the same buckets.
// For each non-empty buckets p, find the next non-empty buckets q, then q.min - p.max could be the potential answer to the question. Return the maximum of all those values.
// 注意最大值最小值相等时size＝0，需要特殊判断

#include "lintcode.h"

class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: the maximum difference
     */
    int maximumGap(vector<int> nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int maxv = 0, minv = INT_MAX;
        for (int &v : nums) {
            maxv = max(maxv, v);
            minv = min(minv, v);
        }
        if (maxv == minv)
            return 0;
        int size = ceil((double)(maxv-minv)/(n-1));
        int len = (maxv-minv)/size+1;
        vector<pair<int, int> > bucket(len, pair<int, int>(-1, -1));
        for (int &v : nums) {
            int idx = (v-minv)/size;
            if (bucket[idx].first == -1) {
                bucket[idx].first = bucket[idx].second = v;
            } else {
                bucket[idx].first = min(bucket[idx].first, v);
                bucket[idx].second = max(bucket[idx].second, v);
            }
        }
        int ans = 0;
        int pre = bucket[0].second;
        for (int i = 1; i < bucket.size(); ++i) {
            if (bucket[i].first == -1)
                continue;
            ans = max(ans, bucket[i].first-pre);
            pre = bucket[i].second;
        }
        return ans;
    }
};


int main(int argc, char const *argv[]) {
    Solution sol;
    vector<int> v = {3,2,1,4,3};
    cout << sol.maximumGap(v) << endl;
	return 0;
}
