// https://leetcode.com/problems/summary-ranges/

#include "leetcode.h"

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.size() == 0) return ans;
        int start = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i]-nums[start] != i-start) {
                stringstream ss;
                ss << nums[start];
                if (i-1 != start)
                    ss << "->" << nums[i-1];
                string s;
                ss >> s;
                ans.push_back(s);
                start = i;
            }
        }
        stringstream ss;
        ss << nums[start];
        if (nums.size()-1 != start)
            ss << "->" << nums[nums.size()-1];
        string s;
        ss >> s;
        ans.push_back(s);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
