#include "RPN.hpp"

void RPN::parseExpresion(std::string& expression) {
    std::stringstream ss(expression);
    std::string op;
    while (getline(ss, op, ' ')) {
        if (op.size() != 1 || allowed.find(op) == std::string::npos) {
            throw std::runtime_error("Error");
        }
        if (digit.find(op) != std::string::npos) {
            int number = std::atoi(op.c_str());
            opp.push(number);
        }
        else {
            int num2 = opp.top();
            opp.pop();
            int num1 = opp.top();
            opp.pop();
            int result;
            try {
                result = doMath(num1, num2, op);
            } catch (std::exception& e) {
                std::cout << e.what() << std::endl;
                return ;
            }
            opp.push(result);
        }
    }
    std::cout << opp.top() << std::endl;
}

int    RPN::doMath(int num1, int num2, std::string& op) {
    if (op == "*") {
        return num1 * num2;
    } else if (op == "-") {
        return num1 - num2;
    } else if (op == "+") {
        return num1 + num2;
    } else if (op == "/") {
        if (num2 == 0)
            throw std::runtime_error("Error: git gud");
        return num1 / num2;
    }
    return 0;
}

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {
    this->opp = other.opp;
}

RPN& RPN::operator=(const RPN& assign) {
    if (this == &assign)
        return *this;
    this->opp = assign.opp;
    return *this;
}