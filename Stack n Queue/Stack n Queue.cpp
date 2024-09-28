#include <iostream>
#include <algorithm>
#include <cctype>
#include <sstream>  // For std::stringstream
#include <stack>    // For std::stack
#include "Stack.h"

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^';
}

int applyOperator(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    case '^': return pow(a, b);
    default: return 0;
    }
}

int evaluatePostfix(const string& postfix) {
    stack<int> operandStack;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            operandStack.push(stoi(token));
        }
        else {
            int b = operandStack.top(); operandStack.pop();
            int a = operandStack.top(); operandStack.pop();
            int result = applyOperator(a, b, token[0]);
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int main() {
    Stack stackForPostfix;
    string infix, postfix = "";

    cin >> infix;
    int n = infix.length();

    for (int i = 0; i < n; i++) {
        char current = infix[i];

        if (isdigit(current)) {
            while (i < n && isdigit(infix[i])) {
                postfix += infix[i];
                i++;
            }
            postfix += ' ';
            i--;
        }
        else if (isalpha(current)) {
            postfix += current;
            postfix += ' ';
        }
        else if (current == '(') {
            stackForPostfix.push(current);
        }
        else if (current == ')') {
            while (!stackForPostfix.isEmpty() && stackForPostfix.top() != '(') {
                postfix += stackForPostfix.top();
                postfix += ' ';
                stackForPostfix.pop();
            }
            stackForPostfix.pop();
        }
        else {
            while (!stackForPostfix.isEmpty() &&
                precedence(stackForPostfix.top()) >= precedence(current)) {
                if (current == '^' && stackForPostfix.top() == '^') {
                    break;
                }
                postfix += stackForPostfix.top();
                postfix += ' ';
                stackForPostfix.pop();
            }
            stackForPostfix.push(current);
        }
    }

    while (!stackForPostfix.isEmpty()) {
        postfix += stackForPostfix.top();
        postfix += ' ';
        stackForPostfix.pop();
    }

    cout << "Postfix Expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
