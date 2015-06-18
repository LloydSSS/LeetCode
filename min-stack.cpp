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

class MinStack {
public:
    stack<int> st;
    stack<int> minst;
    MinStack() {

    }

    void push(int number) {
        st.push(number);
        if (minst.empty() || minst.top() >= number)
            minst.push(number);
    }

    int pop() {
        int retv = st.top();
        st.pop();
        if (retv == minst.top())
            minst.pop();
        return retv;
    }

    int min() {
        return minst.top();
    }
};

int main(int argc, char const *argv[]) {
    return 0;
}
