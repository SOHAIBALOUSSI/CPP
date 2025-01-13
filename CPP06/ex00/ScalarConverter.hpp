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

    static void convertChar(const std::string& literal);
    static void convertInt(const std::string& literal);
    static void convertFloat(const std::string& literal);
    static void convertDouble(const std::string& literal);
    static void convert(const std::string& literal);
};

#endif
