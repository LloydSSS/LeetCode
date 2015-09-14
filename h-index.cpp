// https://leetcode.com/problems/h-index/
// 排序

#include "lc.h"

bool mycmp(int a,int b){
    return a > b;
}
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), mycmp);
        int i = 0;
        for (; i < citations.size(); ++i) {
            if (citations[i] < i+1)
                break;
        }
        return i;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
