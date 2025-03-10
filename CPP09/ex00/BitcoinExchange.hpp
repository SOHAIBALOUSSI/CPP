#pragma once

#include <bits/stdc++.h>

const std::string digits = "0123456789";

class BitcoinExchange
{
    private:
        std::map<std::string, std::string> Btcdata;
    public:
        void        loadBtcData();
        void        loadInputFile(char* infile);
        void        parseKey(std::string& key);
        void        parseValue(std::string& value);
        std::string findExchangeRate(std::string& DateKey);

        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        BitcoinExchange& operator=(const BitcoinExchange& assing);
};

