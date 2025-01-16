#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <bits/stdc++.h>

typedef void (*Converters)(const std::string&);

enum e_type {
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    SPECIAL,
    UNKOWN
}; 

class ScalarConverter
{
private:

    ScalarConverter();
    ScalarConverter(const ScalarConverter &other);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter();
public:

    static bool isFloat(const std::string& s);
    static bool isInt(const std::string& s);
    static bool isDouble(const std::string& s);


    static void convertChar(const std::string& literal);
    static void convertInt(const std::string& literal);
    static void convertFloat(const std::string& literal);
    static void convertDouble(const std::string& literal);
    static void convert(const std::string& literal);
};

#endif
