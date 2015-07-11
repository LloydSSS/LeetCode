// http://www.lintcode.com/en/problem/expression-evaluation/
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
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        stack<string > oper;
        stack<int> number;

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
                    int b = number.top();
                    number.pop();
                    int a = number.top();
                    number.pop();
                    number.push(calc(op, a, b));
                }
                oper.push(symbol);
            } else if (symbol == "(") {
                oper.push(symbol);
            } else if (symbol == ")") {
                while (oper.top() != "(") {
                    string op = oper.top();
                    oper.pop();
                    int b = number.top();
                    number.pop();
                    int a = number.top();
                    number.pop();
                    number.push(calc(op, a, b));
                }
                oper.pop();
            } else {
                number.push(atoi(symbol));
            }
        }
        while (!oper.empty()) {
            string op = oper.top();
            oper.pop();
            int b = number.top();
            number.pop();
            int a = number.top();
            number.pop();
            number.push(calc(op, a, b));
        }
        if (number.empty())
            return 0;
        return number.top();
    }

    int atoi(const string &s) {
        stringstream ss;
        ss << s;
        int i;
        ss >> i;
        return i;
    }

    int calc(const string &op, const int a, const int b) {
        switch(op[0]) {
            case '+':
                return a+b;
            case '-':
                return a-b;
            case '*':
                return a*b;
            case '/':
                return a/b;
        }
        return 0;
    }
};

int main(int argc, char const *argv[]) {
	Solution sol;
    vector<string> v = {"2", "*", "6", "-", "(", "23", "+", "7", ")", "/", "(", "1", "+", "2", ")"};
    cout << sol.evaluateExpression(v) << endl;;
	return 0;
}
