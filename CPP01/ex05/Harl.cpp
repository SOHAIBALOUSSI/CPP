#include "Harl.hpp"

void Harl::debug( void ){
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}
void Harl::info( void ){
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}
void Harl::warning( void ){
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n";
}
void Harl::error( void ){
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
}

e_Level convertLeveltoEnum(std::string strLevel) {
    if (strLevel == "DEBUG") return DEBUG;
    else if (strLevel == "INFO") return INFO;
    else if (strLevel == "WARNING") return WARNING;
    else if (strLevel == "ERROR") return ERROR;
    else return UNKNOWN;
}

void Harl::complain( std::string level ){
    
    e_Level inputLevel = convertLeveltoEnum(level);
    if (inputLevel == UNKNOWN) {
        std::cout << "Unkown level\n";
        return ;
    }
    FuncPtr FuncTable[4] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };
    (this->*FuncTable[inputLevel])();
}