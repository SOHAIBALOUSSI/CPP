#pragma once

#include <bits/stdc++.h>

const std::string allowed = "0123456789-+/*";
const std::string digit = "0123456789";

class RPN
{
private:
    std::stack<int> opp;
public:

    void parseExpresion(std::string& expression);
    int    doMath(int num1, int num2, std::string& op);

    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& assign);
};


