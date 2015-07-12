// http://www.lintcode.com/en/problem/largest-rectangle-in-histogram/
// Time:O(n2)
// 枚举
// Time:O(n)
// 使用stack，栈里面保存着递增序列，如果出现一个小于栈顶元素的高度，则将弹出并处理，直到栈为空或者栈顶元素大于新高度，将新高度压栈
// 在数组最后加入一个0可以去掉边界判断

#include "lintcode.h"

class Solution {
public:
    /**
     * @param height: A list of integer
     * @return: The area of largest rectangle in the histogram
     */
    int largestRectangleAreaStack(vector<int> &height) {
        if (height.size() == 0) return 0;
        //height.insert(height.begin(), 0);
        height.push_back(0);
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[st.top()] <= height[i])
                st.push(i);
            else {
                while (!st.empty() && height[st.top()] > height[i]) {
                    int h = height[st.top()];
                    st.pop();
                    int w = st.empty() ? i : i-st.top()-1;
                    ans = max(ans, h*w);
                }
                st.push(i);
            }
        }
        return ans;
    }

    int largestRectangleArea(vector<int> &height) {
        if (height.size() == 0) return 0;
        height.push_back(0);
        int ans = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i+1] >= height[i])
                continue;
            int h = height[i];
            for (int j = i; j >= 0; --j) {
                if (height[j] < h)
                    h = height[j];
                ans = max(ans, h*(i-j+1));
            }
        }
        return ans;
    }
};


int main(int argc, char const *argv[]) {
    return 0;
}
