#include "BitcoinExchange.hpp"


void BitcoinExchange::loadInputFile(char* infile) {
    std::string line;
    std::string input;
    std::ifstream INFILE(infile);

    if (!INFILE.is_open())
        throw std::runtime_error("Error: cannot open file.");
    
    int turns = 0;
    while (getline(INFILE, line)) {
        if (++turns == 1 && "date | value" == line) continue;
        
        size_t pipePos = 0;
        if ((pipePos = line.find('|')) == std::string::npos) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
    
        std::string key = line.substr(0, pipePos);
        std::string value = line.substr(pipePos+1);
        try {
            parseKey(key);
            parseValue(value);
        } catch (std::exception& e){
            std::cout << e.what() << std::endl;
            continue;
        }
        float nvalue, nexchangeRate;
        try {
            nvalue = std::strtof(value.c_str(), 0);
            nexchangeRate = std::strtof(findExchangeRate(key).c_str(), 0);
        } catch (std::exception& e) {
            std::cout << e.what() << std::endl;
            continue;
        }
        std::cout << key << " => " << value << " = " << nvalue * nexchangeRate << std::endl; 
    }
    INFILE.close();
}

void BitcoinExchange::parseValue(std::string& value) {
    if (value.find('.', value.find('.')+1) != std::string::npos) {
        throw std::runtime_error("Error: bad input => " + value);
    }
    if (value.find('-', value.find('-')+1) != std::string::npos) {
        throw std::runtime_error("Error: bad input => " + value);
    }
    value.erase(std::remove_if(value.begin(), value.end(), isspace), value.end());
    long long nvalue;
    
    if (value.find_first_not_of(digits + ".-") != std::string::npos) {
        throw std::runtime_error("Error: bad input => " + value);
    }
    try {
        nvalue = std::strtol(value.c_str(), 0, 10);
    } catch (...) {
        throw std::runtime_error("Error: bad input => " + value);
    }
    if (nvalue < 0) {
        throw std::runtime_error("Error: not a positive number.");

    }
    if (nvalue > 1000) {
        throw std::runtime_error("Error: bad input => " + value);
    }
}

void    BitcoinExchange::parseKey(std::string& key) {
    std::istringstream ss(key);
    size_t firstpos = key.find('-');
    size_t secondpos = key.find('-', firstpos+1);
    if (firstpos == std::string::npos 
    ||  secondpos == std::string::npos) {
        throw std::runtime_error("Error: bad input => " + key);
    }
    std::string year;
    std::getline(ss, year, '-');
    std::string month;
    std::getline(ss, month, '-');
    std::string day;
    std::getline(ss, day, ' ');
    
    if (year.size() > 4 || month.size() > 2 || day.size() > 2) {
        throw std::runtime_error("Error: bad input => " + key);
    }
    if (year.find_first_not_of(digits) != std::string::npos
    || month.find_first_not_of(digits) != std::string::npos 
    || day.find_first_not_of(digits) != std::string::npos) {
        throw std::runtime_error("Error: bad input => " + key);
    }
}


std::string BitcoinExchange::findExchangeRate(std::string& DateKey) {
    std::map<std::string, std::string>::iterator DateIt;
    DateIt = Btcdata.lower_bound(DateKey);
    if (DateIt != Btcdata.end() && DateIt->first == DateKey) {
        return DateIt->second;
    }
    if (DateIt != Btcdata.begin()) {
        --DateIt;
        return DateIt->second;
    }
    return "0";
}

void BitcoinExchange::loadBtcData() {
    std::ifstream CSV("data.csv");
    if (!CSV.is_open()) {
        throw std::runtime_error("Error: cannot open infile\n");
    }
    std::string btcdata;
    while (getline(CSV, btcdata)) {
        std::string date = btcdata.substr(0, btcdata.find(','));
        std::string value = btcdata.substr(btcdata.find(',')+1);
        Btcdata.insert(std::make_pair(date, value));
    }
}


BitcoinExchange::BitcoinExchange(){}


BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy) {
    this->Btcdata = copy.Btcdata;
}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& assing)
{
    if (this == &assing)
        return *this;
    this->Btcdata = assing.Btcdata;
    return *this;
}