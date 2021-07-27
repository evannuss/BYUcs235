#ifndef EXPRESSION_MANAGER_H
#define EXPRESSION_MANAGER_H

#include "ExpressionManagerInterface.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class ExpressionManager : public ExpressionManagerInterface{
public:
    ExpressionManager(){}
    ~ExpressionManager(){}
    
    bool isBalanced(string expression);
    bool process_operator(stack<string> &opStack, string &postfix, string &op);
    bool isRight(char ch);
    bool isLeft(char ch);
    
    int findPrecedence(string op);
    
    string postfixToInfix(string postfixExpression);
    string postfixEvaluate(string postfixExpression);
    string infixToPostfix(string infixExpression);
    vector<string> parseTokens(string expression);
};

#endif