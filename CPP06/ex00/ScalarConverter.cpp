#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other) {
    (void)other;
    return *this;
}

bool    ScalarConverter::isFloat(const std::string& s) {
    if (s[s.length() - 1] != 'f') return false;
    if (s == "nanf" || s == "+inff" || s == "-inff") return true;
    if (s.find(".") == std::string::npos) return false;

    int start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    std::string check = s.substr(0, s.size() - 1);
    return check.find_first_not_of("0123456789.", start) == std::string::npos;
}

bool    ScalarConverter::isInt(const std::string& s){
    int start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    return s.find_first_not_of("0123456789", start) == std::string::npos;
}

bool    ScalarConverter::isDouble(const std::string& s){
    if (s == "nan" || s == "+inf" || s == "-inf") return true;
    if (s.find(".") == std::string::npos) return false;
    
    int start = 0;
    if (s[0] == '-' || s[0] == '+') start = 1;
    std::string check = s.substr(0, s.size() - 1);
    return check.find_first_not_of("0123456789.", start) == std::string::npos;
}

e_type getType(const std::string& s) {
    if (s.size() == 1 && !isdigit(s[0])) return CHAR;
    if (ScalarConverter::isInt(s)) return INT;
    if (ScalarConverter::isFloat(s)) return FLOAT;
    if (ScalarConverter::isDouble(s)) return DOUBLE;
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
    long long val = std::strtoll(literal.c_str(), 0, 10);
    
    std::cout << std::fixed << std::setprecision(1);

    if (val > 127 || val < 0)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(val))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;

    if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << val << std::endl;

    if (std::strtold(literal.c_str(), 0) > std::numeric_limits<float>::max() || std::strtold(literal.c_str(), 0) < -std::numeric_limits<float>::max()) 
        std::cout << "float: overflow" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;

    if (std::strtold(literal.c_str(), 0) > std::numeric_limits<double>::max()|| std::strtold(literal.c_str(), 0) < -std::numeric_limits<double>::max())
        std::cout << "double: overflow" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void    ScalarConverter::convertFloat(const std::string& literal) {
    double val = strtof(literal.c_str(), 0);

    std::cout << std::fixed << std::setprecision(1);

    if (literal == "nanf" || literal == "+inff" || literal == "-inff") {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: " << literal << "\n"
                  << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
        return;
    }

    if (val > 127 || val < 0)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(val))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    
    if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    if (std::strtold(literal.c_str(), 0) > std::numeric_limits<float>::max() || std::strtold(literal.c_str(), 0) < -std::numeric_limits<float>::max()) 
        std::cout << "float: overflow" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;

    if (std::strtold(literal.c_str(), 0) > std::numeric_limits<double>::max()|| std::strtold(literal.c_str(), 0) < -std::numeric_limits<double>::max())
        std::cout << "double: overflow" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void    ScalarConverter::convertDouble(const std::string& literal) {

    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        std::cout << "char: impossible\n"
                  << "int: impossible\n"
                  << "float: " << literal + "f" << "\n"
                  << "double: " << literal << std::endl;
        return;
    }
    long double val = strtold(literal.c_str(), 0);
    std::cout << std::fixed << std::setprecision(1);


    if (val > 127 || val < 0)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(val))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
    
    if (val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
        std::cout << "int: overflow" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;

    if (std::strtold(literal.c_str(), 0) > std::numeric_limits<float>::max() || std::strtold(literal.c_str(), 0) < -std::numeric_limits<float>::max()) 
        std::cout << "float: overflow" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;

    if (std::strtold(literal.c_str(), 0) > std::numeric_limits<double>::max()|| std::strtold(literal.c_str(), 0) < -std::numeric_limits<double>::max())
        std::cout << "double: overflow" << std::endl;
    else
        std::cout << "double: " << static_cast<double>(val) << std::endl;
}

void    ScalarConverter::convert(const std::string& literal) {

    if (literal.empty()) {
        throw std::runtime_error("invalid input");
    }

    int dotCount = 0;
    for (size_t i = 0; i < literal.size(); i++) {
        if (literal[i] == '.') { dotCount++; }
        if (dotCount > 1 || !isprint(literal[i]))
            throw std::runtime_error("invalid input");
    }

    Converters ScalarConverters[4] = { &convertInt, &convertChar, &convertFloat, &convertDouble };

    e_type type = getType(literal);
    if (type == UNKOWN) {
        throw std::runtime_error("Unkown type");
    }
    ScalarConverters[type](literal);
}
