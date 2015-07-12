// http://www.lintcode.com/en/problem/expression-tree-build/
// 注意弹出计算时要使用while，因为有可能有+*+的情况

#include "lintcode.h"

// Definition of ExpressionTreeNode:
class ExpressionTreeNode {
public:
    string symbol;
    ExpressionTreeNode *left, *right;
    ExpressionTreeNode(string symbol) {
        this->symbol = symbol;
        this->left = this->right = nullptr;
    }
};

class Solution {
public:
    /**
     * @param expression: A string array
     * @return: The root of expression tree
     */
    ExpressionTreeNode* build(vector<string> &expression) {
        stack<string > oper;
        stack<ExpressionTreeNode *> number;

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
                    ExpressionTreeNode *node = new ExpressionTreeNode(oper.top());
                    oper.pop();
                    node->right = number.top();
                    number.pop();
                    node->left = number.top();
                    number.pop();
                    number.push(node);
                }
                oper.push(symbol);
            } else if (symbol == "(") {
                oper.push(symbol);
            } else if (symbol == ")") {
                while (oper.top() != "(") {
                    ExpressionTreeNode *node = new ExpressionTreeNode(oper.top());
                    oper.pop();
                    node->right = number.top();
                    number.pop();
                    node->left = number.top();
                    number.pop();
                    number.push(node);
                }
                oper.pop();
            } else {
                number.push(new ExpressionTreeNode(symbol));
            }
        }
        while (!oper.empty()) {
            ExpressionTreeNode *node = new ExpressionTreeNode(oper.top());
            oper.pop();
            node->right = number.top();
            number.pop();
            node->left = number.top();
            number.pop();
            number.push(node);
        }
        if (number.empty())
            return nullptr;
        return number.top();
    }
};


int main(int argc, char const *argv[]) {
	Solution sol;
    vector<string> v = {"2","*","6","-","(","23","+","7",")","/","(","1","+","2",")"};
    auto root = sol.build(v);
	return 0;
}
