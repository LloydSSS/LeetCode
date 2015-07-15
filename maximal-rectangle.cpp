// http://www.lintcode.com/en/problem/maximal-rectangle/
// Time:O(nm) Space:O(nm)
// 使用largestRectangleArea方法，对于矩阵的每一行以及它上面的行，看做成一个直方图，可以调用largestRectangleArea方法，依次进行计算
// 对于每个点，计算它的左边界，右边界以及高度，在每个点上计算的是包含这个点所能达到最大高度的矩形面积

#include "lc.h"

class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        height.push_back(0);
        int res = 0;
        stack<int> st;
        int i = 0;
        while (i < height.size()) {
            if (st.empty() || height[st.top()] <= height[i])
                st.push(i++);
            else {
                int t = st.top();
                st.pop();
                int width = st.empty() ? i : i-st.top()-1;
                int area = height[t] * width;
                if (res < area) res = area;

            }
        }
        height.pop_back();
        return res;
    }
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int res = 0;
        int h = matrix.size(), w = matrix[0].size();

        vector<int> height(w, 0);
        for (int i = 0; i < w; ++i) {
            height[i] = matrix[0][i] - '0';
        }
        res = max(res, largestRectangleArea(height));
        for (int j = 1; j < h; ++j) {
            for (int i = 0; i < w; ++i) {
                if (matrix[j][i] == '0')
                    height[i] = 0;
                else
                    height[i]++;
            }
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
};

class Solution2 {
public:

    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int i, j;
        int *H = (int*) malloc(n * sizeof(int)); // 高度
        int *L = (int*) malloc(n * sizeof(int)); // 左边界
        int *R = (int*) malloc(n * sizeof(int)); // 右边界
        int ret = 0;
        memset(H, 0, n * sizeof(int));
        memset(L, 0, n * sizeof(int));
        for (i = 0; i < n; i++) R[i] = n;
        for (i = 0; i < m; ++i) {
            int left = 0, right = n;
            // calculate L(i, j) from left to right
            for (j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++H[j];
                    L[j] = max(L[j], left);
                } else {
                    left = j + 1;
                    H[j] = 0;
                    L[j] = 0;
                    R[j] = n;
                }
            }
            // calculate R(i, j) from right to left
            for (j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right);
                    ret = max(ret, H[j] * (R[j] - L[j]));
                }
                else {
                    right = j;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
	return 0;
}
