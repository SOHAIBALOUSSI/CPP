#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {}


enum e_type {
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    UNKOWN
}; 

bool    isFloat(const std::string& s) {
    if (s[s.size()] != 'f') return false;
    int start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    return s.find_first_not_of("0123456789", start) == std::string::npos;
}

bool    isInt(const std::string& s){
    int start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    return s.find_first_not_of("0123456789", start) == std::string::npos;
}

bool    isDouble(const std::string& s){
    
}

e_type getType(const std::string& s) {
    if (s.size() == 1 && isalpha(s[0])) return CHAR;
    // if (isFloat(s)) return FLOAT;
    if (isInt(s)) return INT;
    // if (isDouble(s)) return DOUBLE;
    return UNKOWN;
}

void    ScalarConverter::convert(const std::string& literal) {
    // parse input
    /*
        char
        int
        float
        double
    */
    // for (int i=0; i< literal.size(); i++) {
    //     if (!isprint(literal[i])) throw std::runtime_error("non printable detetcted");
    // }

    e_type type = getType(literal);
    if (type == INT) {
        int val = std::strtol(literal.c_str(), 0, 10);
        std::cerr << val << "\n";
        if (errno == ERANGE) throw std::runtime_error("overflow detected");
        if (val > 255 || val < 0 || !isprint(val))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(val) << std::endl;
        std::cout << "int: " << val << std::endl;
        std::cout << "float: " << static_cast<float>(val) <<  std::endl; 
        std::cout << "double: " << static_cast<double>(val) << std::endl;
    }
    else if (type == CHAR) {
        char val = literal[0];
        std::cout << "char: " << val << std::endl;
        std::cout << "int: " << static_cast<int>(val) << std::endl;
        std::cout << "float: " << static_cast<float>(val) <<  std::endl; 
        std::cout << "double: " << static_cast<double>(val) << std::endl;
    }
    else if (type == FLOAT) {

    }
    if (type == UNKOWN) throw std::runtime_error("UNKOWN type");

}