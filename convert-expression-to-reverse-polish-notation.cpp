// http://www.lintcode.com/en/problem/convert-expression-to-polish-notation/
// 注意弹出计算时要使用while，因为有可能有+*+的情况
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The Reverse Polish notation of this expression
     */
    vector<string> convertToRPN(vector<string> &expression) {
        stack<string > oper;
        stack<vector<string> > number;

        unordered_map<string, int> priority;
        priority["("] = 0;
        priority["+"] = 1;
        priority["-"] = 1;
        priority["*"] = 2;
        priority["/"] = 2;
        for (string &symbol : expression) {
            if (symbol == "+" || symbol == "-" ||
                symbol == "*" || symbol == "/") {
                while (!oper.empty() && priority[oper.top()] >= priority[symbol]) {
                    string op = oper.top();
                    oper.pop();
                    vector<string> b = number.top();
                    number.pop();
                    vector<string> a = number.top();
                    number.pop();
                    vector<string> res(1, op);
                    res.insert(res.begin(), b.begin(), b.end());
                    res.insert(res.begin(), a.begin(), a.end());
                    number.push(res);
                }
                oper.push(symbol);
            } else if (symbol == "(") {
                oper.push(symbol);
            } else if (symbol == ")") {
                while (oper.top() != "(") {
                    string op = oper.top();
                    oper.pop();
                    vector<string> b = number.top();
                    number.pop();
                    vector<string> a = number.top();
                    number.pop();
                    vector<string> res(1, op);
                    res.insert(res.begin(), b.begin(), b.end());
                    res.insert(res.begin(), a.begin(), a.end());
                    number.push(res);
                }
                oper.pop();
            } else {
                number.push(vector<string>(1, symbol));
            }
        }
        while (!oper.empty()) {
            string op = oper.top();
            oper.pop();
            vector<string> b = number.top();
            number.pop();
            vector<string> a = number.top();
            number.pop();
            vector<string> res(1, op);
            res.insert(res.begin(), b.begin(), b.end());
            res.insert(res.begin(), a.begin(), a.end());
            number.push(res);
        }
        if (number.empty())
            return vector<string>();
        return number.top();
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;

	return 0;
}
