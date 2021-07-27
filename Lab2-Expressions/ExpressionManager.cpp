#include "ExpressionManager.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <sstream>

using namespace std;

const string LEFT = "([{";
const string RIGHT = ")]}";

bool ExpressionManager::isRight(char ch){
    return RIGHT.find(ch) != string::npos;
}

bool ExpressionManager::isLeft(char ch){
    return LEFT.find(ch) != string::npos;
}

bool ExpressionManager::isBalanced(string expression){
    stack<char> parentheses;
    bool balanced = true;
    string::const_iterator iter = expression.begin();
    
    while (balanced && iter != expression.end()){
        char nextCharacter = *iter;
        
        if (isLeft(nextCharacter)){
            parentheses.push(nextCharacter);
        }
        else if (isRight(nextCharacter)){
            if (parentheses.empty()){
                balanced = false;
            }
            else{
                char topCharacter = parentheses.top();
                parentheses.pop();
                balanced = (LEFT.find(topCharacter) == RIGHT.find(nextCharacter));
            }
        }
        iter++;
    }
    return balanced && parentheses.empty();
}

string ExpressionManager::postfixToInfix(string postfixExpression){
    stack<string> expressions;
    vector<string> parsedTokens = parseTokens(postfixExpression);
    
    if (postfixExpression.find('.') != string::npos){
        return "invalid";
    }
    
    for (int i = 0; i < parsedTokens.size(); i++){
        if (isdigit(parsedTokens.at(i)[0])){
            expressions.push(parsedTokens.at(i));
        }
        else if (parsedTokens.at(i) == "*" || parsedTokens.at(i) == "+" || parsedTokens.at(i) == "-" || parsedTokens.at(i) == "/" || parsedTokens.at(i) == "%"){
            if (expressions.size() < 2){
                return "invalid";
            }
            string rightOperand = expressions.top();
            expressions.pop();
            
            string leftOperand = expressions.top();
            expressions.pop();
            
            string infixString = "( "  + leftOperand + ' ' + parsedTokens.at(i) + ' ' + rightOperand + " )";
            expressions.push(infixString);
        }
        else {
            return "invalid";
        }
    }
    if (expressions.size() == 1){
        return expressions.top();
    }  
    else{
        return "invalid";
    }
}

string ExpressionManager::postfixEvaluate(string postfixExpression){
    stack<int> operandStack;
    vector<string> parsedTokens = parseTokens(postfixExpression);
    
    for (int i = 0; i < parsedTokens.size(); i++){
        if (isdigit(parsedTokens.at(i)[0])){
            stringstream stringToInt(parsedTokens.at(i));
            int intToken = 0;
            stringToInt >> intToken;
            operandStack.push(intToken);
        }
        else if (parsedTokens.at(i)[0] == '*'){
            if (operandStack.size() < 2){
                return "invalid";
            }
            int rightOperand = operandStack.top();
            operandStack.pop();
            int leftOperand = operandStack.top();
            operandStack.pop();
            operandStack.push(leftOperand * rightOperand);
        }
        else if (parsedTokens.at(i)[0] == '+'){
            if (operandStack.size() < 2){
                return "invalid";
            }
            int rightOperand = operandStack.top();
            operandStack.pop();
            int leftOperand = operandStack.top();
            operandStack.pop();
            operandStack.push(leftOperand + rightOperand);
        }
        else if (parsedTokens.at(i)[0] == '-'){
            if (operandStack.size() < 2){
                return "invalid";
            }
            int rightOperand = operandStack.top();
            operandStack.pop();
            int leftOperand = operandStack.top();
            operandStack.pop();
            operandStack.push(leftOperand - rightOperand);
        }
        else if (parsedTokens.at(i)[0] == '/'){
            if (operandStack.size() < 2){
                return "invalid";
            }
            int rightOperand = operandStack.top();
            operandStack.pop();
            int leftOperand = operandStack.top();
            operandStack.pop();
            if (rightOperand == 0){
                return "invalid";
            }
            operandStack.push(leftOperand / rightOperand);
        }
        else if (parsedTokens.at(i)[0] == '%'){
            if (operandStack.size() < 2){
                return "invalid";
            }
            int rightOperand = operandStack.top();
            operandStack.pop();
            int leftOperand = operandStack.top();
            operandStack.pop();
            operandStack.push(leftOperand % rightOperand);
        }
        else{
            return "invalid";
        }
    }
    
    ostringstream intToString;
    
    intToString << operandStack.top();
    string result = intToString.str();
    
    operandStack.pop();
    return result;
}

vector<string> ExpressionManager::parseTokens(string expression){
    stringstream ss(expression);
    string oneToken;
    vector<string> tokens;
    while(getline(ss, oneToken, ' ')){
        tokens.push_back(oneToken);
    }
    return tokens;
}


string ExpressionManager::infixToPostfix(string infixExpression){
    string postfix = "";
    stack<string> operatorStack;
    vector<string> tokens = parseTokens(infixExpression);
    
    if (infixExpression.find('.') != string::npos){
        return "invalid";
    }
    
    for (int i = 0; i < tokens.size(); i++){
        if (isdigit(tokens.at(i)[0])){
            postfix.append(tokens.at(i) + ' ');
        }
        else if (tokens.at(i) == "*" || tokens.at(i) == "+" || tokens.at(i) == "-" || tokens.at(i) == "/" || tokens.at(i) == "%" ||
                    tokens.at(i) == "(" || tokens.at(i) == ")" || tokens.at(i) == "{" || tokens.at(i) == "}" || tokens.at(i) == "[" || tokens.at(i) == "]"){
            if (process_operator(operatorStack, postfix, tokens.at(i)) == false){
                return "invalid";
            }
        }
        else{
            return "invalid";
        }
    }
    while (!operatorStack.empty()){
        if (operatorStack.size() > 1){
            postfix.append(operatorStack.top() + ' ');
            operatorStack.pop();
        }
        else if (operatorStack.size() <= 1){
            postfix.append(operatorStack.top());
            operatorStack.pop();
        }
    }
    if (postfixEvaluate(postfix) == "invalid"){
        return "invalid";
    }
    else {
        return postfix;
    }
}

bool ExpressionManager::process_operator(stack<string> &opStack, string &postfix, string &op){
    if (opStack.empty() || isLeft(opStack.top().at(0)) || isLeft(op.at(0)) ){
        opStack.push(op);
        return true;
    }
    else if (isRight(op.at(0))){
        while (!isLeft(opStack.top().at(0))){
            postfix.append(opStack.top() + ' ');
            opStack.pop();
            if (opStack.empty()){
                return false;
            }
        }
        opStack.pop();
        return true;
    }
    else{
        while (!opStack.empty() && findPrecedence(op) <= findPrecedence(opStack.top())){
            postfix.append(opStack.top() + ' ');
            opStack.pop();
        }
        opStack.push(op);
        return true;
    }
}

int ExpressionManager::findPrecedence(string op){
    if (op == "*" || op == "/" || op == "%"){
        return 2;
    }
    else if (op == "+" || op == "-"){
        return 1;
    }
    else{
        return 0;
    }
}