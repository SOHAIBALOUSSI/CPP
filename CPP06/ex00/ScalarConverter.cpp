#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    return *this;
}


enum e_type {
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    SPECIAL,
    UNKOWN
}; 

bool    isFloat(const std::string& s) {
    if (s[s.length() - 1] != 'f') return false;
    if (s.find(".") == std::string::npos) return false;
    int start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    std::string check = s.substr(0, s.size() - 1);
    return check.find_first_not_of("0123456789.", start) == std::string::npos;
}

bool    isInt(const std::string& s){
    int start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    return s.find_first_not_of("0123456789", start) == std::string::npos;
}

bool    isDouble(const std::string& s){
    if (s.find(".") == std::string::npos) return false;
    
    int start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    std::string check = s.substr(0, s.size() - 1);
    return check.find_first_not_of("0123456789.", start) == std::string::npos;
}

e_type getType(const std::string& s) {
    if (s.size() == 1 && isalpha(s[0])) return CHAR;
    if (isInt(s)) return INT;
    if (isFloat(s)) return FLOAT;
    if (isDouble(s)) return DOUBLE;
    return UNKOWN;
}

void    ScalarConverter::convertChar(const std::string& literal) {
    char val = literal[0];
    std::cout << "char: " << val << std::endl;
    std::cout << "int: " << static_cast<int>(val) << std::endl;
    std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl; 
    std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

void    ScalarConverter::convertInt(const std::string& literal) {
    long val = std::strtol(literal.c_str(), 0, 10);
    if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min()) {
        throw std::runtime_error("overflow");
    }

    if (val > 255 || val < 0 || !isprint(val))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(val) << std::endl;

    // if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
    //     std::cout << "int: impossible" << std::endl;
    // else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    
    // if (val > std::numeric_limits<float>::max() || val < std::numeric_limits<float>::min()) {
    //     std::cout << "float: imposible" <<  std::endl; 
    // }
    // else
        std::cout << "float: " << static_cast<float>(val) << ".0f" <<  std::endl; 
    // if (val > std::numeric_limits<double>::max()|| val < std::numeric_limits<double>::min())
    //     std::cout << "double: " << "imposible" << std::endl;
    // else
        std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
}

void    ScalarConverter::convertFloat(const std::string& literal) {
    bool zeroFract = literal.find(".0") != std::string::npos;
    float val = strtof(literal.c_str(), 0);

    std::cerr << val << std::endl;
    std::cerr << "max val = " << std::numeric_limits<float>::max()  << std::endl;
    std::cerr << "min val = " << std::numeric_limits<float>::min()  << std::endl;
    // if (val > std::numeric_limits<float>::max() || val < std::numeric_limits<float>::min()) {
    //     throw std::runtime_error("float overflow");
    // }
    if (val > 255 || val < 0 || !isprint(val))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(val) << std::endl;
    // if (val > std::numeric_limits<float>::max()|| val < std::numeric_limits<float>::min())
    //     std::cout << "int: impossible" << std::endl;
    // else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    if (zeroFract) {
        std::cout << "float: " << static_cast<float>(val) << ".0f" <<  std::endl; 
        std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
    }
    else {
        std::cout << "float: " << val << "f" <<  std::endl;
        std::cout << "double: " << static_cast<double>(val) << std::endl;
    }
}

void    ScalarConverter::convertDouble(const std::string& literal) {
    bool zeroFract = literal.find(".0") != std::string::npos;

    double val = strtod(literal.c_str(), 0);
    if (val > std::numeric_limits<double>::max()|| val < std::numeric_limits<double>::min()) {
        throw std::runtime_error("overflow detected");
    }
    if (val > 255 || val < 0 || !isprint(val))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(val) << std::endl;
    std::cout << "int: " << static_cast<int>(val) << std::endl;
    if (zeroFract) {
        std::cout << "float: " << static_cast<float>(val) << ".0f" <<  std::endl; 
        std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
    }
    else {
        std::cout << "float: " << val << "f" <<  std::endl; 
        std::cout << "double: " << static_cast<double>(val) << std::endl;
    }
}


void    ScalarConverter::convert(const std::string& literal) {

    int dotCount = 0;
    if (literal.empty()) {
        throw std::runtime_error("invalid input");
    }
    for (int i=0; i< literal.size(); i++) {
        if (literal[i] == '.') dotCount++;
        if (dotCount > 1 || !isprint(literal[i])) throw std::runtime_error("invalid input");
    }

    e_type type = getType(literal);

    bool zeroFract = literal.find(".0") != std::string::npos;

    switch (type)
    {
    case CHAR:
        convertChar(literal);
        break;
    case INT:
        convertInt(literal);
        break;
    case FLOAT:
        convertFloat(literal);
        break;
    case DOUBLE:
        convertDouble(literal);
        break;
    case SPECIAL:
        // convert(literal);
        break;
    default:
        break;
    }

    if (type == INT) {
  
    }
    else if (type == CHAR) {
    }
    else if (type == FLOAT) {

    }
    else if (type == DOUBLE) {

    }
    else {
        throw std::runtime_error("UNKOWN type");
    }
}