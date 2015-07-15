// https://leetcode.com/problems/text-justification/
// 细节题

#include "lc.h"

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
        int left = 0, right = 0, len = 0;

        for (right = left; right < words.size(); ++right) {
            len += words[right].size();
            if (len+right-left > L) {
                len -= words[right].size();
                right--;
                int word_num = right - left + 1;
                int space_num = L - len;
                int space_avg = (word_num == 1) ? space_num : (space_num/(word_num-1));
                int space_left = (word_num == 1) ? 0 : (space_num%(word_num-1));
                string line = "";
                for (int i = left; i <= right ; ++i) {
                    line += words[i];
                    for (int j = 0; j < space_avg && (i != right || word_num == 1); ++j)
                        line += " ";
                    if (space_left != 0) {
                        space_left--;
                        line += " ";
                    }
                }
                result.push_back(line);
                left = right+1;
                len = 0;
            }
        }
        right--;
        int last_word_num = right - left + 1;
        int last_space_num = L - len - last_word_num + 1;
        //int space_avg = (word_num == 1) ? space_num : (space_num/(word_num-1));
        //int space_left = (word_num == 1) ? 0 : (space_num%(word_num-1));
        string line = "";
        for (int i = left; i <= right ; ++i) {
            line += words[i];
            if (i != right)
                line += " ";
        }
        for (int i = 0; i < last_space_num; ++i)
            line += " ";
        result.push_back(line);
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    return 0;
}
