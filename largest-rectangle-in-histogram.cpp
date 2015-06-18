#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

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
