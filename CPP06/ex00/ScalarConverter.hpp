#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <bits/stdc++.h>

class ScalarConverter
{
private:

public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();

    static void convert(const std::string& literal);
};

#endif
