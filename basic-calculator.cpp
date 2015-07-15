// https://leetcode.com/problems/basic-calculator/
// 调用evaluateExpression

#include "lc.h"

class Solution {
public:
    int calculate(string s) {
        vector<string> expression;
        string num;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                num += c;
            } else {
                if (!num.empty()) {
                    expression.emplace_back(num);
                    num.clear();
                }
                if (c != ' ')
                    expression.emplace_back(1, c);
            }

        }
        if (!num.empty()) {
            expression.emplace_back(num);
            num.clear();
        }
        return evaluateExpression(expression);
    }
    /**
     * @param expression: a vector of strings;
     * @return: an integer
     */
    int evaluateExpression(vector<string> &expression) {
        stack<string > oper;
        stack<long long> number;

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
                    long long b = number.top();
                    number.pop();
                    long long a = number.top();
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
                    long long b = number.top();
                    number.pop();
                    long long a = number.top();
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
            long long b = number.top();
            number.pop();
            long long a = number.top();
            number.pop();
            number.push(calc(op, a, b));
        }
        if (number.empty())
            return 0;
        return number.top();
    }

    long long atoi(const string &s) {
        stringstream ss;
        ss << s;
        long long i;
        ss >> i;
        return i;
    }

    long long calc(const string &op, const long long a, const long long b) {
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
    return 0;
}
